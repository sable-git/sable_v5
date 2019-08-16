/*********************************************************
  Pfam_el_315new390.c
  --------------------------------------------------------
  generated at Tue Aug  3 11:14:14 2004
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
0.903630, 0.925110, -0.317650, -0.777240, -0.616780, 0.119430, 0.038370, 0.373470, -0.372110, 0.170300,
0.520740, 0.638810, 0.732260, -0.326390, 0.408920, 0.444810, 0.446520, 0.898500, 0.555480, -0.084820,
-2.308420, 1.077470, -0.322150, -0.613170, 0.161900, 0.414180, -0.969300, -0.165670, 0.709270, -0.547130,
-1.160170, -0.742100, 0.370450, -0.552490, 0.232750, 1.554420, 0.105410, 1.163590, -0.938140, -0.467970,
2.434810, -0.681900, -0.564600, 0.508240, 1.678010, 0.371760, -1.448610, 0.706540, 0.810510, 1.617290,
0.017900, -0.660160, -0.026340, -1.313360, -0.717840, 1.098850, -0.722830, -0.734750, -0.006350, -0.214680,
0.841020, -1.175510, -0.008270, 0.575880, 0.292320, -1.015340, 0.435360, 1.285370, 0.549110, 0.788430,
-0.320390, 0.799860, -0.408000, -1.251860, 1.090930, 1.438610, 0.664720, 0.068450, 0.081600, -0.959390,
0.099200, 0.341440, -1.392570, 0.319710, -0.511940, -1.584990, -1.399660, 1.654480, -0.009850, -4.420270,
0.523870, -2.053080, -0.112470, -0.280180, -0.315960, -0.743160, -0.274560, 0.154020, -0.017100, -0.985540,
-0.448490, -0.004110, 1.115960, 0.570620, 0.873330, 0.605910, -0.440330, 0.106810, 1.459020, 0.565490,
0.421960, -0.974190, -0.548860, -0.793520, -0.757890, -1.224460, 1.336660, 0.632440, 1.364240, 0.921830,
0.943850, 0.390260, 0.971890, 0.736110, 2.361010, -0.217390, -1.521540, -0.338530, -3.381300, -0.773590,
-2.738770, 0.423750, 4.464620, -0.366990, -1.138990, 9.313010, 0.676000, 0.759370, 0.193500, -0.299870,
-1.688360, -0.169670, -0.524710, -0.452690, -0.075650, -0.347220, -0.093660, 0.860100, -0.004360, 0.287960,
-0.539610, -0.580240, 1.653330, -0.237530, 0.300170, -0.900330, -0.811280, 0.292410, -0.431540, -1.433190,
0.992200, -1.219550, -1.563570, -0.231880, -0.150330, -0.482220, -1.167580, -0.631400, -0.010630, -0.095730,
0.466120, 0.940370, 0.346830, -0.355460, -1.013800, 0.039150, -1.072690, -0.862980, -2.065330, 0.904740,
-0.803290, -0.741810, -0.941390, -0.267440, -1.403170, 0.881780, 0.390540, -0.218040, 0.635390, -0.944670,
-0.579360, -0.047070, 0.050340, 0.895710, 2.371750, 0.082840, 0.449710, 1.756330, 0.169400, 0.957770,
0.092150, 0.409410, 0.126110, 1.116860, 0.863020, 0.388070, 0.004250, 0.813810, -0.656160, -0.267700,
0.189670, -1.087380, -0.604780, 1.033990, -0.255980, 0.413700, 1.108260, 0.005600, -0.015190, -0.108690,
0.228540, 1.148480, 0.192300, 0.035200, 0.014260, -0.692680, -0.496690, -0.960690, -0.390940, 0.733680,
0.545640, -0.420470, -0.221630, -1.418740, 0.080610, 1.082580, 1.295970, 1.585880, -0.108510, -0.371880,
-0.682510, 0.720990, -0.468320, -0.533550, -0.448970, -0.818060, 1.220710, 0.299020, -1.221280, -0.918770,
-0.149570, 0.478130, 0.001760, -1.687760, 2.126360, 0.662150, 0.052100, -0.271770, 0.365840, -7.222240,
1.299540, -0.851990, -2.223850, 0.000390, 3.366830, -0.334900, -0.691400, 0.301310, 0.427380, -0.844500,
-0.157050, -3.772220, 0.512900, -0.160470, -1.462330, 0.326600, -1.024950, 0.104620, 2.654830, -0.252300,
0.006270, -0.792740, -1.872320, -0.308370, -0.642370, -1.580660, -1.957050, -0.955560, -0.456870, -1.262670,
0.366270, -1.390060, 0.726670, 0.551420, -0.662000, -0.703690, -0.177040, -0.610970, -1.084540,
-1.662100, 0.343060, -1.239520, -0.292510, -1.316500, -1.360060, 1.016620, 0.761170, -1.042970, 0.183990,
-0.569990, 1.895660, -0.574650, 0.230480, 0.975110, 1.066800, 0.518740, -0.516240, -0.570490, 0.324910,
-0.163890, 0.141690, -2.301610, -0.697790, 0.695300, -2.031710, -2.756450, -0.178950, 0.456680, 0.885400,
0.032980, 0.631000, -1.508940, 1.340400, 1.927910, 1.094500, -0.168120, -0.413550, -0.272230, -1.464110,
-1.824660, -1.013120, 0.946350, -0.614930, 0.628150, 0.042970, -0.765310, 2.169000, 2.403910, -0.019560,
0.424570, 0.610540, -0.797080, 1.141990, 0.386400, 1.310760, -0.895500, -0.146710, -0.204880, 2.002830,
-1.413580, 0.429040, -1.041760, -2.581110, 0.656020, -0.672570, 0.435170, 0.033870, 0.359990, 0.222670,
-0.533460, 0.469210, 0.886480, -2.038010, -1.666950, -0.587170, 0.779970, -0.484780, -0.010250, -1.193720,
1.634450, 1.502410, 0.124710, -0.960060, 0.316800, -2.473980, -1.822650, -1.624540, -0.398960, 0.542140,
0.427290, -0.845090, 0.885090, -0.042410, 0.736190, -1.469620, 0.560680, 0.211670, -1.423790, -0.303400,
0.372860, 1.201690, 0.060550, -1.768270, -0.062700, -2.877140, -0.931450, 1.218730, -0.126330, -0.035090,
-0.983190, -0.177310, 1.376300, -0.684670, 1.149390, -1.346910, -0.058780, -1.058310, -1.707420, 0.470940,
-1.555350, 0.625920, -0.913000, -1.505730, -3.000090, 0.317600, -0.373060, 0.580820, -2.242230, 1.087250,
-0.051550, 0.060410, -2.942300, 0.147320, 1.789860, -0.676650, -0.741010, 1.714810, -0.004160, 3.821480,
-0.109360, -1.247010, -0.147260, 0.936690, -1.155240, -0.223350, 1.483670, -0.569000, 0.289870, -0.379850,
-1.346590, 1.077690, 1.179230, -0.189550, -0.399680, -0.842600, -0.348370, -0.091070, 0.361860, -0.153310,
-0.946880, -0.481580, 0.168910, -2.404410, -1.443040, 0.234920, -1.447120, -0.163140, 0.489180, 0.559110,
1.322040, 1.208250, 0.018490, 0.717970, -1.202880, -1.239050, 1.332590, 0.048680, -0.621000, -0.423570,
1.515380, 0.114430, -0.531410, 0.473200, -1.040320, 0.748700, -1.823160, 1.480310, -1.636860, -1.425180,
0.075050, 0.608080, -0.264940, -0.009070, 0.350100, -0.234050, 0.282280, -0.378760, -0.856550, 0.160670,
1.199150, -2.032990, -2.096830, -0.670340, 0.087400, 0.948180, 0.098260, 0.111600, 0.683270, 0.195360,
-1.659890, 0.873000, 0.141750, -0.613220, 0.747460, 1.026960, 0.559600, 0.321740, -0.601170, 0.263860,
-0.248530, -0.288520, 1.942540, -0.991850, -0.875940, 0.664170, 0.705330, -0.181970, -0.824330, -0.678670,
-0.355630, -0.128220, 0.773490, 1.522940, -0.089200, 0.361320, 0.933860, -1.469530, 0.242530, 0.299290,
1.399470, 0.602740, 0.126860, -0.293940, -0.500760, -1.679090, -0.112010, -0.047790, -0.950270, -1.191360,
0.991130, -1.342980, -0.639960, 0.924110, 1.042740, 1.525460, 0.860080, -1.245420, 0.009510, 0.604990,
1.869330, -0.525970, 1.451100, 0.472490, -0.535280, 1.256410, -0.570660, 1.185130, -0.730800, 0.222120,
0.426880, 0.446870, 0.820290, -0.427510, -0.734520, 0.654970, 0.151500, 0.234630, -0.164870, 1.003850,
-0.108700, 0.318380, -0.192630, -1.051420, -0.012290, 0.073960, -0.259230, -0.999220, -0.962940, 0.242490,
-0.285040, -0.096410, -1.078920, 0.697290, -0.901350, -1.004960, 0.763850, 0.070820, -2.208120,
0.014950, 4.109260, 1.958800, -0.093450, 0.017540, -0.769290, 0.374940, -0.641170, 2.430290, -0.103510,
0.026530, -0.362270, 0.354820, 1.288110, 0.249450, -0.221740, 0.827030, -0.597640, -1.211510, 0.831790,
1.263300, -0.030240, 0.094080, -0.041380, -0.842500, -0.051840, -0.330730, 0.265730, 1.276630, 1.252920,
0.780090, 0.366030, 0.646600, 0.727900, -0.476780, -1.362960, 0.435610, 1.602320, 0.289680, 1.202110,
-0.767940, -1.517180, -0.544800, 0.587620, -1.504700, 0.047700, 0.640350, 1.459040, -1.562480, 0.344330,
-0.792070, -0.530270, -0.283700, -0.246010, -0.810050, -1.420190, -0.907560, 0.277270, 0.215310, 1.075580,
2.007350, 0.773700, 0.072790, -2.058210, -0.804710, 0.295600, 0.451000, -0.028920, -0.753120, -1.787410,
0.517860, -0.055810, -0.427580, -0.968520, -0.631270, 0.396760, -0.050420, -3.431860, 0.109840, 0.822970,
-0.961140, -0.220770, -0.272740, 0.356320, 0.089170, -0.335640, -1.258680, -0.568680, -0.250280, -0.569270,
0.446150, 1.788480, 0.213000, -0.636980, -1.266690, -0.703080, -1.520310, -0.547300, -1.038260, -0.881050,
-0.365300, -0.694300, -0.593200, -1.140030, -1.249330, 1.885040, 1.008400, -0.573000, -0.395890, -0.504610,
-1.070400, 0.358230, 0.273230, -0.464020, 0.776800, 0.024660, -0.286200, -2.471540, -0.988380, -1.113100,
-0.223680, 2.059140, 0.729800, -4.326660, -2.863620, -1.029560, 0.733760, -0.414900, 0.898990, -0.021030,
0.782410, -0.236710, -5.771470, 0.866470, -0.169680, -1.802140, 0.100780, 5.658790, -1.317130, 0.681930,
-0.611650, -0.556560, 0.382200, 0.874220, -0.424320, -1.701100, -0.731050, -1.044230, 0.477860, 0.311440,
-1.759550, -1.245630, -2.957060, -1.435240, 0.801860, -5.242150, 0.546960, 0.529950, -0.263720, -0.051960,
-0.374790, -0.440880, -2.230370, -1.246700, 1.824080, 0.342580, -0.028740, 0.311040, -3.222000, -0.986150,
-1.616850, 0.382820, 0.660660, 0.574840, 0.211870, 0.153280, 1.696560, 2.407090, 0.675430, -0.354450,
0.029780, 1.267710, 0.804300, 0.554150, -0.545890, -1.699390, -0.737690, 0.863000, 0.304860, 0.567720,
-1.636940, 0.977690, -0.399970, -0.248980, 1.452500, -1.207140, 0.288240, 0.612840, -1.095730, -0.621610,
1.214790, -0.013790, -0.648150, 1.184840, 0.955470, -1.037040, 3.245760, -0.708960, -2.729060, 0.590850,
1.320130, -1.252150, -1.085160, 0.209780, -0.401800, 1.183010, -2.268530, -1.043450, -0.913860, 0.405070,
1.114150, 1.364520, 0.137460, 0.223890, 0.220070, 1.849620, 0.966080, -0.461430, 0.977010, 0.490780,
-0.561660, -1.818120, -0.349650, 0.588880, -0.184780, -1.513810, 0.728030, -0.389210, -0.161660, -1.692620,
0.622680, 0.900880, -1.003200, -1.370120, -0.325820, 0.057770, 0.769210, -0.879260, -0.773200, 1.156880,
1.432240, 0.510460, 0.328960, 1.764630, -0.333570, -2.315700, 0.356700, 0.518340, 0.015040, 2.650130,
0.097410, 0.946180, 0.858370, -0.234540, 0.014400, -3.370580, 0.329640, 0.734880, 0.489690, -0.303040,
0.077060, -1.035810, 0.547140, 0.495670, 0.045890, -0.895160, -0.181760, -0.016280, 0.125110, -0.549890,
0.581530, -0.636380, 0.235240, -0.365210, 0.862270, 3.585560, 0.125030, 1.572550, -0.524100, -0.443330,
-0.261040, 0.181410, -0.254700, 0.220360, 0.671560, -0.087480, -0.978000, 0.750180, -2.512080,
-1.277680, 0.701870, 0.005580, -0.528040, 0.148510, 1.735640, -0.587840, -0.427470, -0.693050, -1.717500,
0.191430, -1.680380, -0.950340, 1.817910, 0.118000, 0.889160, -0.570590, -0.359240, -0.361620, -0.219310,
0.646630, -1.151900, -0.363320, 0.518390, 0.726700, -1.363340, -0.289760, -1.301890, 0.207160, 0.204000,
1.205070, -0.206770, -1.385730, -0.439000, 0.739120, 0.861790, 0.137050, 1.375860, -1.079420, -0.447040,
-0.138170, 0.382780, -0.498800, 1.346530, 1.177500, 2.258080, -0.022740, -0.895770, -1.856500, 0.156370,
-1.138640, 0.184630, -0.642540, 0.897200, -0.643220, -1.312600, -0.485870, -0.159400, -1.228220, 1.308410,
-0.979240, -0.986080, -0.067770, -0.307750, -0.528070, -0.745970, -1.066520, -0.311470, -0.853370, -0.504180,
-1.328250, 0.235200, 0.871800, -0.353850, -1.302140, 0.212800, -1.077700, 0.241370, -0.043190, 2.590210,
0.619700, -0.033190, -1.061600, -1.920980, -0.937330, 1.012390, 0.127430, -0.562470, 1.420000, 0.109290,
0.686290, 0.356720, -0.658960, -0.821030, -1.200410, -0.417360, -4.878150, -0.755230, 3.902480, -1.159650,
-0.783260, -2.614480, 0.925950, 0.167410, 0.803190, 1.707750, -0.285860, 0.307620, 0.530030, -1.790270,
3.246680, -0.070590, 0.191400, 0.191920, 0.750530, -0.671660, -0.799080, -2.216530, 0.496100, 0.705400,
-0.523780, 1.833540, 0.503150, 0.972890, -3.759550, 0.839700, 0.867390, 1.067620, -1.240350, -0.073860,
2.311130, 2.172190, -0.335640, 3.152690, 1.094530, -2.586540, 0.900080, -0.822000, -1.935610, 1.102630,
-2.182970, -0.609840, -0.880180, 3.407830, 0.965330, 1.850940, -0.882640, -0.447160, 0.907300, 2.140980,
1.064490, -0.581790, 0.275970, 0.147290, 1.599550, -1.505130, -0.765540, 0.391420, -1.041910, 0.780110,
-0.261430, 0.219510, 0.566640, -0.369910, 0.986690, 0.394960, -0.003580, -0.261300, -0.243110, 0.849000,
1.080500, -0.828850, -0.803240, -0.649610, 2.009760, 0.425790, 0.571570, 0.110920, -0.851620, 0.353400,
0.685940, 0.543040, -2.148760, -0.651520, 1.427270, 0.121390, -0.214620, -2.297500, 0.406200, -0.607190,
-1.075870, 2.031410, 0.420040, 0.241750, 0.515770, 1.167040, 1.222020, 0.562600, 0.450600, 0.355950,
-0.166660, 0.693790, -0.420920, 0.728870, -0.436780, 0.083670, 0.221460, 0.399940, 0.311680, 0.457220,
-1.988320, 0.850700, 0.359910, -0.238880, 0.450110, -0.558370, 0.362510, -1.628660, 0.693470, -0.378050,
-0.358460, 0.315070, -0.699370, 0.492460, -1.185900, -1.054790, -1.371250, -0.858540, 3.258560, -0.256100,
-0.718080, 0.309740, 0.911180, 1.307330, -0.295350, 0.977360, 0.741620, 0.629480, 0.647380, -0.173510,
0.261650, -1.171200, 0.924080, 2.094810, -0.319770, 0.876070, -0.345070, -0.176580, -0.462870, 0.818280,
0.500510, -0.766490, 0.065370, 1.161020, 0.044390, -0.330860, -1.116880, -1.607940, -0.340890, -0.751760,
0.223080, -0.177320, -1.083230, -1.220200, -0.920050, -0.449600, -0.566760, -1.265950, -0.180990, -0.619240,
0.847800, 0.130310, 0.920410, -0.255400, 0.315320, -0.780330, -0.877420, -0.660820, 0.824730, -0.063250,
-1.294230, 0.211300, 0.553940, -0.333440, -0.829300, -0.486520, -0.879350, -0.655490, -1.079510, 1.015640,
0.192230, -0.687460, 0.805550, 0.303320, -0.311730, 0.542780, -0.307590, -0.491350, -0.169610,
0.465930, 0.246760, 0.785940, 0.134770, 0.073690, -0.758350, 0.407020, 0.546030, 0.399000, -0.396630,
-0.928760, -1.508990, 1.521890, -1.014870, -0.727970, 0.416950, 0.458060, -0.569390, -0.681540, 0.077700,
0.028860, 0.233690, -2.389070, -0.036800, 0.030920, 0.055820, -0.296560, 0.535070, 0.805350, -1.482290,
0.495250, 0.535330, 0.570280, -0.322460, -0.230470, -2.205730, 0.247620, 0.153660, 0.939200, 0.533970,
1.204400, 0.753040, -1.384870, 0.227820, 0.908510, 0.031080, -0.673600, 1.595470, 0.170040, -0.266630,
0.211310, 1.233030, -0.036280, -0.246450, 1.113740, -0.250740, 0.088130, -0.914450, 0.063590, -1.951070,
0.892650, 0.111090, -0.039100, 1.213390, 0.440770, 1.219810, -1.068410, -0.459640, -0.593890, 0.688660,
0.717310, 1.344860, -1.474870, 1.347750, -0.625380, -0.958010, 0.366830, -0.310110, -0.399480, 0.336340,
0.858940, 0.476510, -0.412070, -2.300540, -0.702160, -1.024880, 1.348700, -0.779260, 0.422570, 0.253900,
0.368070, 0.333580, 0.444590, 1.631360, 1.202570, -0.648680, -1.040350, 1.085410, 0.976380, -0.339690,
0.700720, 0.277980, 0.025330, -1.047890, -1.144170, 0.000280, -0.514600, -0.394200, 0.208870, -0.225360,
-0.559460, -0.745500, 0.076070, -0.790360, 1.174380, 0.805920, 1.926220, 1.025530, 0.225290, 3.038060,
0.415950, -2.532000, -1.038880, 2.636800, 3.004070, -0.188360, -1.656780, -2.193630, 2.092080, -0.756160,
-0.874830, 0.437770, 6.266520, -0.590660, -0.007260, 13.142030, -0.301600, 1.460890, 0.763990, 0.718430,
-0.244210, -0.409500, 0.662990, 0.364430, -0.328110, 1.101340, 0.515180, -0.522130, 0.251570, -0.381150,
-0.873600, -0.804990, -0.819100, 0.153070, -1.675070, -0.093120, 0.093910, -0.546150, -2.860160, 0.461100,
-0.753850, 1.260140, 2.609870, 1.092710, 0.786740, -0.119040, 0.209740, -0.889920, -0.529300, 0.464340,
-0.255310, -0.746430, 1.124840, -1.913570, -1.113950, 0.495590, -1.826200, 0.544150, -0.004970, -0.688440,
-0.382370, -1.970860, 0.127340, 1.392710, -0.220880, -1.590520, 2.236920, -1.311160, 0.040820, 1.625750,
-0.134840, 0.130270, -0.211750, 0.767290, 0.348760, 0.212160, -0.543340, 0.531270, -0.468510, -1.964380,
-1.019330, 1.761040, -1.586530, 0.629790, 1.113520, -1.571020, 1.348340, 1.000700, 0.909750, 0.735190,
0.372400, -0.895510, -0.132650, -1.115180, -0.701210, 1.081410, 0.866270, 0.447060, -0.103430, 0.709750,
-0.987150, -0.023830, 0.386890, 0.232890, 2.321380, 0.067880, -0.114080, -0.601650, 0.748800, 0.102990,
0.332540, 0.282100, 2.068010, -0.402030, -0.549440, 0.088810, 0.051680, 0.177350, -0.001210, 0.455220,
-0.089520, 0.771360, 0.395380, -0.653440, 0.315070, -0.542620, 0.573810, 1.132780, -1.603440, 0.586000,
0.572340, -0.398270, 0.311470, 1.354150, -0.003670, 1.545890, 0.328160, -0.081800, 1.457200, 0.518300,
0.721610, 0.857910, -0.863570, 0.817260, 1.062650, -0.344930, 0.635550, 0.587970, 0.519940, 0.339140,
-0.854620, -1.241540, 0.573130, 0.218220, -1.279910, 0.873420, 0.950660, 0.415310, -1.162620, 0.601300,
-0.167760, 0.567400, -0.142050, 0.514890, 0.033530, -2.078620, -0.210320, 0.691770, -1.212190, 0.418630,
-0.688050, -1.206160, -0.667490, -0.001300, -1.070830, 0.550800, 0.450960, 0.092520, -0.122450,
0.297550, -0.480470, -0.157690, -0.917580, 0.596910, 0.366920, -0.332050, 0.499700, -0.975250, -0.523200,
-0.038280, -0.523360, 0.034940, -0.078340, -1.568750, 0.628510, 0.022950, 0.704510, 0.325930, -1.211200,
1.486070, -0.072160, 1.264510, -0.727220, -0.521390, -0.335980, -1.055470, -0.761480, 0.574160, 0.034280,
-0.139740, 0.410410, -0.710760, 0.033970, -0.834030, -0.234250, 0.286100, -0.105760, 0.705890, -0.774510,
-0.511960, -0.636460, -0.380780, 1.205180, 1.715610, 0.944990, 0.024840, 0.167450, -1.269870, 0.247500,
0.313930, -0.157390, -0.114830, 0.586330, 0.767420, 0.229320, -0.623460, -0.197630, -0.063460, 0.344260,
0.314950, 0.254790, 0.985780, 0.365620, 0.503150, -0.676100, -0.057460, 0.480710, 0.044400, -0.033900,
0.643000, -0.218790, 0.641540, -0.303790, -0.354220, -0.494880, -1.327920, 0.726680, 0.539900, -0.558080,
-0.723780, -0.112800, -0.393710, -0.183080, -0.624960, -0.031550, -0.221070, -0.121220, -0.106810, 2.523510,
0.144920, 0.050980, -0.135000, -0.424470, -1.489050, 0.275730, 0.603190, -0.939400, 1.692150, -0.002680,
0.687470, 1.627170, 0.347790, -0.465160, 1.375810, 1.108180, 0.526900, -0.452010, -0.976200, 0.985630,
-0.025040, -0.695970, 0.640040, 0.513130, -0.356450, -2.873130, -0.138930, -3.423960, 5.872110, -2.274550,
-0.037780, 1.965260, 1.773660, -1.120330, -2.866550, -1.561950, 0.796920, -1.095260, -0.732810, -2.101930,
-0.817940, 0.775870, -2.488910, 0.292240, 0.829160, -2.571700, 2.699440, 1.736640, 0.586080, -0.578950,
-0.834570, -0.673140, 0.123640, -0.274870, 1.060220, 0.640800, 0.391910, 0.200510, -0.182800, -1.864530,
0.075180, -1.202630, 1.299750, -0.650530, 0.956810, -0.146440, 0.895820, 0.338100, 0.089870, -1.074110,
0.175290, 1.185530, -0.576300, -0.112770, -0.491220, -1.019990, -0.385650, 0.588120, -0.930380, -0.253470,
0.465660, -0.500430, 0.605150, -0.592890, -0.667320, -0.577700, -1.074050, 0.796520, -1.700740, -0.697780,
-0.105770, 1.175750, -0.084890, 0.301500, 0.480220, -0.161620, -0.920520, 0.170600, -0.464870, 0.480050,
0.399350, -0.642670, 0.415560, 0.568420, 0.264380, -0.995910, -0.004560, -0.117560, 0.003880, -0.677770,
0.623310, -0.106020, -0.544990, -0.908630, -0.717000, -0.247190, 2.868990, 1.498140, 1.066160, -0.388260,
-0.180210, 0.180330, 0.636430, 0.304740, -0.873680, 0.171540, -0.633510, -0.410190, 0.605460, -0.053180,
1.131500, -0.364470, -0.312870, -0.873010, -0.053960, 2.326660, 0.078140, -0.200500, 1.138490, 1.517960,
0.093260, 0.270430, 0.098090, -0.267390, -0.764230, -1.651090, 0.051540, -0.568990, 0.582410, 0.113810,
-0.266210, 0.526230, -1.061680, -0.286730, -0.526580, -1.121320, -0.091490, 0.692450, -0.746420, 1.290170,
0.731070, -0.481290, -0.505050, -8.883300, 0.357540, -0.445280, -0.842870, -0.269350, 0.049970, 1.603190,
-0.929870, -1.336950, -0.655050, -0.378670, -0.098420, 0.357640, -0.172180, 0.450410, -1.233140, -0.710730,
-0.878290, -0.239920, -1.164900, -0.476410, -0.516470, -0.340750, -1.685560, -1.809200, -1.401570, 0.171330,
-0.016290, -1.014700, 0.133590, -0.653790, -0.887660, -1.572280, -1.794510, -1.126470, -0.423700, -1.147370,
-0.023780, -1.569780, -1.480670, -0.819590, -1.133190, -0.340120, -1.482810, -1.156400, -0.002440,
-0.324180, 0.729200, 0.761560, -2.206120, 0.395500, 0.303390, -1.955820, -0.924470, -1.604560, -0.216950,
1.563020, -1.405580, -1.242140, -1.940580, 0.464780, -0.751400, -0.263090, -1.731530, -1.580150, 1.654710,
-0.428140, -0.259270, 0.047370, 0.583870, -0.677250, -0.446250, -1.152810, -0.909440, -1.990900, -0.289280,
0.982340, -0.474480, 0.842190, 0.799030, -0.902510, 0.305980, -0.482590, 0.384120, 1.215360, 0.540750,
-1.148790, -0.262700, -0.250920, -0.885780, -0.445420, -0.729150, -1.724100, -0.714520, -0.219210, -0.202890,
0.746510, 0.572060, 0.201040, 0.569810, -0.458890, -0.151280, -0.515110, -0.354080, 0.811730, -0.030910,
-2.519960, 0.163950, 0.143020, -1.182220, -0.111610, 0.658960, -0.577810, -1.131750, -1.584020, -0.375140,
1.617800, -0.133400, -0.403400, 0.006670, 1.173370, 0.846820, 0.120570, 0.869850, -2.252280, 0.577240,
1.474130, -0.305980, -0.732090, -0.873400, -2.333530, -0.546600, -0.090500, 0.911850, 0.629890, -0.788070,
-1.357520, 0.060220, -0.895600, -0.102900, -1.945620, -1.255360, -0.814990, -0.137930, -0.777110, -0.112230,
-0.592540, -2.617030, -0.254700, 1.194060, -0.170230, 0.055990, 0.006640, -1.205620, -0.157120, -1.305770,
-1.265050, -0.012830, -0.061270, -0.015860, 0.108010, 1.129770, 1.144020, 1.349740, -2.179550, 3.193900,
1.287840, -1.269520, 4.673010, 1.824400, 2.825990, -0.195190, -0.863690, -0.863100, 2.786310, 0.162760,
1.250460, -1.262040, 3.631580, -1.355630, 0.583040, 5.629110, 0.119330, -1.003270, 1.771740, -0.619500,
-1.240110, -1.739070, -1.053440, -0.894130, 0.168600, 0.393830, 0.321820, -0.523430, 2.473320, 0.132860,
-0.331690, -0.706920, -0.678680, -1.065970, -1.138000, -1.138120, -0.161720, 2.068710, 0.983510, -0.113660,
-0.402580, 0.478320, 0.282180, -2.710840, -0.725850, -0.992370, -2.033320, -1.370560, 0.702690, -1.340970,
0.529730, -2.157000, -1.252730, 0.187320, 0.520620, 0.602180, -0.754010, -0.202430, 0.184490, -0.407440,
-1.625110, -0.083090, -1.858110, -1.126790, -0.827400, 0.729310, 0.017180, -2.213650, 1.244410, 2.054930,
-0.385300, -1.527530, 0.087530, 0.475490, 0.700100, 0.036550, -0.211320, 0.189430, -0.241480, -0.409580,
0.230080, 1.058330, 0.796310, -0.198550, -0.596950, -0.678340, 0.440940, -0.021780, 2.063050, 0.302970,
-0.460040, -0.315160, 0.079270, 2.094290, 1.149850, 0.583060, -1.201910, 1.072280, 1.133440, -0.431350,
0.218660, -1.265160, 0.984250, 0.346920, -0.123780, -0.581670, -0.424020, -1.509170, -0.312090, -0.917990,
-1.490350, 0.147050, 0.247610, -2.502360, -0.388310, -0.046050, 0.497840, -1.913020, -0.900880, -1.909020,
0.943060, 0.630750, -1.766960, 0.142860, -0.166640, -1.524310, 0.679230, -0.245030, 0.699980, 0.656270,
-0.760000, -0.138010, 0.189050, -10.735590, -0.033720, -0.595210, 0.003960, -0.268170, -1.236170, 1.858100,
-0.425400, 0.528870, -4.738470, -2.290190, 0.830610, 2.271030, 0.229080, 0.450580, -0.268190, 1.902550,
-0.522550, -1.044870, 0.864260, 1.053600, -0.060910, 0.038510, -0.001540, 0.736250, -0.760300, -0.773010,
0.868670, -0.115840, -0.860500, -0.911740, 1.032100, -0.442940, -0.551600, -1.665280, -0.039000, 2.687170,
-0.052760, -0.727460, 0.785410, 0.411830, 0.882810, 0.357380, -0.279720, 0.163350, 0.219480,
3.068750, -1.608950, -0.539540, 0.764580, 0.174550, 0.682650, -0.180120, -3.688660, 0.648310, -0.927110,
-0.777320, -0.157410, 0.358290, -0.570320, -1.030010, 0.232370, 1.595580, 1.922220, 0.759000, -0.962320,
-0.079230, 0.063610, 0.604480, -1.871770, -1.647920, 1.942120, 0.416930, 1.904980, 0.836770, 0.847310,
-0.965220, 1.690430, 1.045660, 0.558320, -1.890170, 0.210990, 1.210390, 0.012920, -0.886560, -1.286120,
0.440950, -0.106280, 0.474020, -1.789890, -0.937760, -1.591620, 0.122570, 0.717680, 1.131440, -0.245260,
1.445010, -0.118600, 0.052120, 1.864380, 0.286110, 1.725110, 0.493270, 0.597860, -0.955310, 1.776880,
5.496970, 1.807120, -0.566400, 1.253460, -0.087820, 0.059640, 0.226050, -0.023790, -1.286040, 1.940060,
0.594510, -0.108340, -2.506780, 0.218950, 0.096970, -0.830980, -0.326570, 2.051380, -1.474210, -0.054720,
-0.176500, 1.123870, 5.645310, -0.776160, -1.136880, 0.899830, -1.177820, 0.821250, -0.895090, -1.612430,
-1.045420, -0.763750, 3.033320, 1.262910, -0.561750, 0.022950, 0.787410, 0.370830, 0.848900, -0.118350,
0.507530, 0.156890, 0.813720, -0.664720, -3.120110, -0.618850, 1.965740, 0.902730, -1.089190, 0.558730,
0.338540, 0.180440, 0.171950, -0.029890, 1.457040, 0.366060, 0.517650, -0.760820, 1.475210, -1.187470,
-0.581510, -2.470690, 0.606670, -1.190970, 1.027930, -1.177220, -1.532210, 0.042570, 2.223780, -0.165170,
-3.463340, -0.338660, 1.012930, -0.279040, -0.526180, -1.006360, 0.645730, -4.254730, 0.424230, -0.854400,
3.360110, -0.541100, 0.532820, 0.689490, 0.043150, 0.708300, 0.241070, -0.271650, -1.957980, -1.939070,
0.016340, -0.160210, 0.951280, 0.411770, 0.292000, -0.747930, 1.520500, 0.348830, -0.814000, 0.131490,
-0.010290, 0.261240, -0.468380, -1.194860, 0.074290, -0.193460, -0.273140, 0.801070, -0.849890, 0.206800,
-3.066370, 0.157730, -1.206500, -0.146290, 1.509800, 0.494850, 1.315260, -1.218350, -0.900780, -0.334540,
1.548590, -0.781000, 0.110290, -0.424200, 2.864280, 0.326160, -0.893170, -0.342620, -1.332770, -1.269280,
0.018740, -0.406120, -0.692830, -1.357810, 1.078980, 0.350750, 0.434420, 0.478940, 1.470430, -0.315270,
0.052990, -1.166990, -0.326670, 0.070000, -1.237130, -0.296000, -2.869350, -0.492240, 0.403480, -0.545410,
-0.749980, -0.590900, -0.642920, 0.001550, 0.460820, 1.784640, 1.016160, 0.685370, 0.751480, -0.152520,
0.527770, -0.046140, 0.541270, 0.870710, 1.600670, 0.806110, 0.881980, -1.539580, -0.367010, -1.486020,
-0.754800, 1.923940, -0.740640, -2.375960, 1.513640, 0.419520, 0.152250, -1.879010, -1.095800, 2.107300,
-0.448500, -0.728790, -0.111460, 1.442790, 0.121020, 0.275080, 1.644530, 1.515780, 2.926780, 0.777480,
-1.109550, 0.603240, 0.173550, -1.390950, 0.110660, 0.774410, 1.168940, -1.176230, 0.820880, -0.193620,
-1.595280, -0.788790, -2.055060, 0.673430, 1.954850, 0.713480, 0.473490, -0.138090, -0.612980, 0.307980,
0.688890, -0.924210, 0.457260, 0.493700, -0.721930, 1.238810, 0.330980, 0.666090, -0.117590, -0.998550,
-1.810180, 0.780290, -0.621700, 1.554040, 0.467450, 0.389310, -0.139710, 0.294460, -0.673890, -0.737290,
0.357390, -0.622080, -0.658690, -0.319750, 0.870740, 0.117320, 0.822370, -0.561070, -0.158780,
1.209160, 0.555480, -0.808720, 0.280070, -1.179260, 0.388710, 0.371510, -0.369610, -0.835630, 0.099490,
-0.482690, 0.355490, -0.666350, -0.524320, -0.523860, -1.106430, 0.029780, 0.661490, 0.158600, -0.583490,
-1.022030, 0.079560, 0.943240, -0.582930, 0.106470, 0.716990, -0.103350, 0.160080, 1.411980, 0.432580,
-0.504770, -0.987220, 1.907570, 0.799470, -0.883480, 0.177500, -0.206730, 0.883830, -0.270370, 1.052950,
-0.138690, -0.289650, -0.590910, -0.920280, -0.265990, -0.733690, -0.428770, 0.552910, 0.843160, 2.008040,
-0.219740, -1.194020, -0.266840, 0.454850, 2.022470, 1.040250, -1.238750, 0.392130, -0.422940, 0.379450,
-0.800370, -0.325970, -1.062810, -0.446170, 1.566740, 0.889050, -0.005000, 0.097650, 0.215190, 0.891960,
0.283660, -0.863140, -0.216010, 0.933440, 0.453650, -0.367100, 1.859040, -1.809450, -0.753210, -1.283250,
-1.040180, -0.439980, -0.870500, -0.534730, -0.016210, -0.373860, -0.724230, -0.214650, 0.909800, -0.600280,
-0.718550, 1.762430, -0.518500, 0.605960, -0.073740, -0.318800, -0.414500, 0.975430, -0.255790, -0.333690,
-0.038800, -0.731660, -1.590350, 0.061230, 0.141240, 0.668910, -0.920900, -0.484700, -0.971750, 0.037300,
-0.736330, -0.853800, 0.389150, 1.399950, 0.687190, 0.497200, -0.131340, 2.077920, -4.615320, 3.238700,
-1.551640, -4.747440, 0.683480, 3.349800, 1.865230, -1.005490, -2.471630, 0.505520, -0.304300, 2.085610,
0.544740, -2.010780, 1.361500, -1.541320, -2.016120, 1.844590, 0.907560, -0.251840, -0.104540, 1.109020,
-0.087440, -1.159630, -0.309210, 0.312190, 0.482700, 0.663420, 1.597150, 0.582560, -1.135260, 0.391290,
-0.457110, 0.400570, 0.234730, -0.472550, 0.345260, 0.553960, -0.912700, -0.568720, -0.153180, -0.886580,
-0.037990, 0.122400, 1.755940, -0.394060, -0.130400, -0.388930, 0.903270, 0.150140, 0.777980, 1.157530,
0.046250, -1.372010, 0.647370, -1.226570, 0.095700, 0.101650, -0.229790, -0.111470, -0.191600, 0.724620,
-0.273850, -1.199850, 0.438340, -0.474110, 0.556880, 1.753350, -0.797200, -0.802200, -0.273470, 1.183990,
-0.141550, 0.358750, 0.782130, 1.025160, 0.223070, -0.220380, 0.503310, 0.313950, -1.317590, 1.121950,
-1.391830, -0.251180, -1.787770, -0.331200, -0.065910, 0.801860, -0.203360, 1.103910, 1.828060, 0.590780,
-2.139500, 1.645330, 1.617310, -0.590950, -0.166600, -0.790370, 0.560950, 1.140000, 0.434150, -0.224000,
0.512400, -0.139330, -1.131800, -0.130020, 1.241820, 0.056830, -1.081450, -0.601860, -0.682500, -0.189700,
-1.864970, 0.813140, 0.623040, -0.918330, 0.290490, 1.779250, -0.551620, 1.278100, 1.683050, 1.099870,
0.755190, -0.754730, -1.182300, -0.954300, -0.809650, 0.297550, -0.161630, -0.570160, -1.189610, 1.064900,
-0.395580, -0.167050, 0.780700, 12.600460, 0.043380, 1.877010, -0.110450, 0.198560, 0.289310, -2.599580,
-0.418100, -0.044680, -1.778050, -0.394810, -0.966050, 0.363400, 1.085290, -0.795060, 0.282120, 0.562830,
0.984690, 1.016290, 1.231450, 0.900740, -1.283200, 1.546480, 0.491040, 0.309800, -0.573010, -0.349350,
1.541080, 0.485850, -0.946870, 1.063180, 1.107080, 0.858470, 2.635410, 0.975970, 0.297210, 1.208730,
1.344250, -0.003650, -0.811590, 0.354500, 0.199150, -0.289390, -0.166000, 0.555510, -0.420100,
-0.276290, -0.224120, 0.047050, 0.993110, -1.288140, 0.289240, -0.702580, 0.397150, 0.601900, -0.812560,
0.468630, -1.003870, -0.533550, -0.599240, 0.808320, 2.741700, 0.887310, 0.424830, -1.364490, 0.174080,
-1.519360, -0.217890, 0.355130, -2.544580, -0.941380, 0.465290, 0.458260, -0.541290, 1.107650, 0.118820,
0.132720, -1.378680, -1.147320, 0.428470, -0.927340, -1.182480, -0.147290, 0.138620, -0.051760, 1.020300,
-1.442760, 0.737070, -0.323690, -0.360070, -0.341680, 1.300870, -2.393800, -1.013180, -0.651990, -0.793130,
-0.793250, -0.286700, -1.378240, -0.886360, 0.021800, -0.277270, 0.186170, 1.278880, -1.310090, -0.699920,
-0.108660, -0.676280, 1.343810, -1.407480, 0.717860, 1.974100, -1.030360, -0.103650, 0.833230, -0.802970,
-2.018120, -1.252610, -0.279790, 0.103780, 1.297510, -0.349190, -0.262680, -0.231710, -1.210710, 0.849850,
0.328700, -0.960180, 2.143980, 0.634800, 0.030950, -0.921570, 0.267650, -0.505960, 2.255480, -1.170310,
-0.053700, 2.043820, 0.507820, -0.661970, -0.353390, 0.986560, -1.545810, 0.210420, -0.983020, -0.634810,
-0.711730, -1.724950, -0.624710, -0.420400, 1.056160, 0.157930, -0.730370, 0.567100, 0.799210, 0.541780,
0.343640, -1.814510, 0.332870, -0.235560, -0.055170, -1.151070, -0.888590, -1.016560, 3.484620, -0.485470,
0.088410, -0.098420, -0.208400, 0.118920, -0.949740, 0.977300, -0.442440, -0.400730, 0.134190, 0.885860,
-0.069110, 0.636550, -0.853000, 0.935600, 0.863040, -1.807360, 0.988500, 1.334460, 0.947120, 0.608690,
-3.151570, 0.119050, -0.145650, 0.351210, 0.226440, 0.515060, 2.603870, -1.245400, -0.751980, 0.123120,
-0.544030, -0.106260, -0.397970, 0.710420, 1.201410, 0.875330, -0.112420, 1.175810, 1.409130, 0.478750,
0.691580, 0.046690, 0.398920, 0.769690, -1.112200, -0.709980, 0.930660, -0.743480, -0.951580, 0.278910,
-1.782500, 0.152870, -1.510360, -1.051580, 1.118300, 1.107960, -1.269320, 0.085300, -0.091210, -0.584870,
-0.042490, 2.699070, -0.526920, -0.210140, -0.355500, 0.770440, -0.062620, 0.042710, -0.563010, 0.283770,
0.211620, 1.232080, -1.416070, 0.350340, -3.258790, -0.504350, -0.270060, 0.833320, 0.945340, 0.261850,
-1.305790, -1.027440, -0.028560, 0.591430, 0.700710, 0.244630, 0.579940, 0.654350, 0.054940, 1.057600,
-0.954320, 0.602620, -1.080210, 0.527680, 0.195030, 0.304670, -0.165520, 0.290010, 0.398150, -0.313020,
3.417600, -0.052420, -0.059810, 0.359740, 0.787720, -0.345950, -0.606090, 1.248510, -0.970930, 0.264920,
1.251770, 0.737270, -0.591890, -0.256730, 1.684540, 0.074260, 0.961090, 1.741700, 0.571230, -1.528050,
-1.372160, 0.459750, 0.312320, 2.869750, 0.214300, 0.273870, 0.855870, 0.107570, 0.294360, 1.829520,
1.260340, -0.763430, 0.813610, 0.375780, -0.584990, 0.521200, -1.564210, -0.724560, 0.662760, 0.636520,
-0.086750, 0.400760, -0.443370, 0.449700, 0.505890, -0.368400, -0.633910, -0.565270, -0.848410, -3.109500,
-0.801800, -0.817540, 0.000850, -1.906770, 0.120780, -0.850920, -3.654950, -1.361930, -0.349940, 0.658050,
-0.246480, -5.037370, 0.136790, -2.048430, -0.195280, 0.965290, -1.327030, 0.820420, -1.081590, -0.556460,
0.683470, -0.541290, -0.708310, -0.434380, 0.294750, -0.106100, -1.906440, -0.099870, -0.657170,
-0.800360, -0.277200, -0.993720, -0.156250, -0.216730, -0.641020, -0.842800, 0.822630, 0.285210, -1.028830,
0.202740, -1.801980, -1.526050, 0.916270, 0.269770, -1.543620, 1.039580, -0.089680, -1.287710, 0.642930,
1.749730, 0.788880, 0.916510, -0.392920, -0.000900, 0.833470, 0.401310, 0.202920, -1.672320, -0.156480,
-0.359430, -1.454990, -0.111980, -0.574060, -0.669280, -0.113340, -0.367090, 1.250890, -0.877920, 0.094760,
-0.466000, -0.092170, -1.606870, -0.198940, 1.904310, -0.994170, 0.523090, 0.468980, -0.597970, 0.350190,
0.100500, -0.391010, 1.433650, 0.323230, -1.467930, -1.827370, 0.235080, 0.214570, 0.041570, 2.637060,
1.624590, -0.638330, -0.156420, -0.588840, 0.512330, 0.290350, 0.308790, 0.264080, 0.467030, 0.445220,
-0.194320, -0.018380, -0.187130, -0.737120, 0.303950, 0.024930, -0.381630, -1.337070, 0.317260, -0.268370,
-0.125990, -2.044800, 1.769480, -0.659240, 1.250570, 0.710990, -1.566320, -0.563680, -1.009790, 0.043630,
1.078080, 0.334050, 0.379020, 1.841970, -0.826820, 0.450190, -1.120250, -1.107190, -0.251170, 1.152660,
1.005410, -0.524490, 0.313000, -0.317030, 1.104200, 0.726670, -0.026670, 1.164580, 0.816100, -0.002820,
1.520200, 0.291320, 1.900860, -0.952660, -0.845450, -2.659470, -0.468540, 1.230780, 3.675830, -5.364000,
2.757970, 1.661450, -1.149610, -2.265910, -3.776740, -0.217500, 1.286350, -1.428600, -0.810080, -1.146440,
-1.785860, 0.493920, -2.933220, -0.826210, 0.487190, -8.165780, -1.119740, 1.894780, 0.431200, -0.506560,
-0.547910, -4.549910, 1.499760, 0.469430, -0.083710, 0.430830, -1.038690, 0.041910, -0.150360, -0.139560,
-1.211030, 0.758440, -0.309980, 0.028040, 0.498650, -0.512090, -0.699700, -1.043320, 0.493240, 0.777380,
0.190190, 0.515320, 0.567850, -0.534180, 0.579940, -0.369670, 0.568510, 0.084190, -0.596880, 0.880920,
-1.454350, 0.990630, 0.258500, -1.016200, -0.427460, -0.436290, -0.210690, -0.702670, -1.229330, -1.197660,
1.159070, 0.382930, 0.610780, 0.271780, 0.493320, -0.121970, -1.168450, 2.355290, 0.097050, 0.524600,
0.216090, -0.280380, 0.077440, -0.585450, 0.784090, -0.039820, 0.922150, 1.461320, 1.350780, 0.062810,
0.153360, -4.031860, 0.140050, 1.320910, 0.118400, 0.348010, 0.609260, 0.672880, -0.054180, -0.904850,
-1.744900, -0.763770, -0.306830, 1.164570, -0.214190, 0.403940, 1.408470, 0.624650, 0.418430, 1.297870,
0.736940, 0.692560, 0.548510, 0.701030, 0.411850, 0.366970, -1.158800, 0.976580, -0.091710, 0.366250,
-0.448910, 0.505790, -0.906500, -0.642110, -1.355190, -0.133610, -0.208870, -0.430320, -0.451900, 0.880180,
0.015680, -0.828600, -0.793230, -0.934430, 0.383930, -0.717910, -0.745670, -1.830210, -0.660790, 1.703720,
1.854900, -2.005760, 0.725210, -8.409330, -0.161150, 0.568470, 0.018680, 0.022830, -0.893060, 1.788260,
-0.817400, 0.708430, -1.367750, 1.725470, -0.921350, 2.165430, -0.043610, -1.780000, -0.026650, -3.291740,
-0.345580, -0.339350, -0.557680, -0.472600, -1.064530, 0.321110, -0.260550, -0.384790, -0.562750, -0.809970,
-0.150580, -0.548520, -0.987350, 0.238250, -0.464460, 1.536890, -1.157090, 0.616830, -0.903750, 0.013470,
0.259040, -0.941650, 0.652490, -0.752900, -0.918670, -0.410680, -1.101140, -0.495540, -3.173490,
-0.603890, -1.239040, -0.536500, -0.183010, -1.337340, 0.590220, -0.870980, -0.340110, -0.661810, 1.250650,
-0.255950, -0.593120, 0.409120, 0.389920, 0.364410, -0.574810, -1.578550, 0.374750, 0.742260, 0.241310,
0.387150, -0.730270, 0.022600, -0.395510, -0.411750, -0.006980, 0.350850, -0.552560, 0.669430, -0.412540,
0.095880, 1.283780, -1.060930, -1.563470, 0.699690, -0.981680, -1.097480, -0.603560, -0.808590, -1.661070,
-0.738070, -0.652850, 0.500190, 1.332390, -0.884210, 0.440160, 0.290720, -1.288430, 0.245670, -0.485140,
0.929300, 0.457630, -0.386120, 0.783840, -0.439530, 0.319500, -0.701030, -0.508930, 0.415910, -1.781730,
0.621410, 0.175770, -1.759280, 0.219920, 0.727970, -0.425510, 0.415580, 0.570550, -0.395280, 2.154620,
1.914840, 0.723220, -1.196130, 0.709020, 0.481590, 0.358820, -0.596460, 0.353280, 0.107910, 0.376370,
-0.667620, 0.147760, 1.364880, -1.901250, 1.971930, -0.904600, 0.611460, -0.271790, 1.441500, 0.399380,
-0.398170, -0.455220, 0.085950, -0.724880, 0.039970, -0.333210, -0.735060, 0.964560, 0.697830, -0.663600,
0.077740, -0.397650, -0.511190, 1.104210, -0.001680, 1.739030, -0.954920, 0.296480, -0.651740, 0.575850,
-0.643020, -0.099150, 1.535990, -0.060890, -0.385490, -0.001140, -1.048270, -0.204210, 2.575320, -0.502180,
0.442890, -0.108850, -0.899410, -2.309480, -1.839980, 0.789560, 1.156580, 0.695570, 0.028840, 0.282720,
0.653220, 0.597090, -1.307910, 0.276630, -0.698230, -1.366540, -1.468690, 1.018680, -1.194370, -1.577700,
-0.103670, 0.431460, 0.380820, 0.478090, 0.554520, 1.802270, -0.747120, 1.641740, 0.250530, -0.940790,
0.942100, -0.811630, -0.631430, 0.251760, -0.274320, -0.252900, 1.714120, 0.390840, 0.586000, 1.219070,
0.963960, -1.062690, -1.606330, -0.598020, 2.838780, 0.769190, 0.120150, -0.389400, 0.020330, 0.173010,
-1.224220, 0.120010, -0.215540, -1.744960, 0.344850, -0.970620, -0.754520, -0.352060, -0.662090, -0.669330,
1.404990, 1.789450, 1.207650, 0.987100, 0.160370, -0.289200, 0.382040, 0.802430, -1.307490, -0.753940,
-0.273440, 0.666760, -1.822610, -0.464300, 0.210720, 1.144420, 0.667540, -1.764870, 0.092130, -0.489110,
0.120270, 0.182110, 2.039960, 0.936880, 0.523770, -0.893930, -0.149610, -0.367050, -0.844930, 0.546960,
0.353900, -0.162630, -0.323050, 0.744430, 0.087620, -0.181380, -0.551620, 0.617120, 1.308290, -0.602230,
0.445070, -0.912920, 0.627730, 0.966070, -2.079600, 0.623670, 1.489700, -1.351730, -0.800060, -0.170110,
0.332990, -0.794820, 1.371220, 1.128260, 0.113490, 0.074130, 0.541780, 0.061840, 0.782930, -0.008090,
-0.243620, 0.079890, 0.255360, 0.409160, -0.734170, 1.229760, 0.421360, 1.249470, 0.135730, 0.829320,
-0.814810, 0.000430, 1.747540, -14.129430, -0.149680, 0.333910, -0.814620, -0.929550, -0.265680, 0.992160,
0.774590, 0.054290, 1.127490, 0.974080, 0.614100, -1.263830, -0.934870, -1.160220, -1.232350, 0.507700,
0.553480, 0.261050, 0.188670, -0.772920, -0.017080, 0.443520, -0.075080, 0.161210, -1.076300, 0.368480,
-0.542050, -0.938650, 0.279630, -1.512810, -1.295540, 2.153290, -1.221560, -0.108220, -1.333870, -0.768330,
-0.220950, -0.789290, -0.421880, -1.645320, -1.510790, -1.690040, -1.620520, -0.307710, -3.168430,
-0.519400, 1.702820, -0.614670, 0.593250, -0.659820, -2.198250, -0.196870, 0.253550, -0.472820, -0.654100,
0.341930, 1.218690, 0.455320, 0.910240, -0.276490, 1.363150, -0.030500, 1.444780, 0.701360, -2.463780,
-0.537350, -0.586790, -1.613900, 1.437560, -0.207990, 2.056660, 0.172710, -0.616650, -1.246410, 0.442240,
0.432100, -1.037810, -0.084240, 1.744000, -1.151470, -0.292310, -0.904890, 0.446780, 1.567880, -0.331930,
0.699570, -1.029870, 1.207190, -0.839600, -0.655020, -2.441330, 0.449450, -0.537190, 0.878990, -1.774440,
0.313710, -0.558210, -0.268630, 0.201040, -0.968820, -0.420190, -0.305350, -2.775500, 1.278710, -0.949300,
-0.703300, 0.019460, -1.276040, 0.637340, 0.499170, -0.312660, 0.612740, -0.049760, -0.717380, -0.069060,
0.208200, 0.265760, -0.118790, 0.457250, -0.714130, 0.162780, -1.538920, 0.664590, -1.688160, -0.041070,
1.922940, -0.755610, 0.623750, -0.270670, 2.087880, -0.009440, -0.792330, 1.197970, -0.644170, 0.554270,
0.091780, -2.665890, -0.796450, 0.067710, 1.102960, -1.710540, 0.953340, -1.340680, 0.213810, -0.116610,
0.477250, -0.324110, -1.395470, -0.303670, 1.831900, -0.412200, 1.027750, 0.149700, 0.491570, 1.559010,
-1.572630, -0.298640, 0.343920, -0.177160, -0.490940, 1.480550, 2.321320, -0.589610, -0.232260, -1.227100,
1.052020, -1.337800, 0.135410, 1.426160, 2.668090, -1.368700, 0.214830, -0.364520, 1.303570, -0.506410,
-1.120470, -1.449790, 4.017500, -0.777920, 1.179230, 5.400080, -0.125550, -3.865260, -0.524420, -3.576170,
1.005410, 0.018940, 1.120260, -0.762160, -0.964970, 0.706750, 1.095210, -0.013140, 0.288070, -0.873770,
0.903190, -1.311080, 2.396600, 1.707840, 1.659170, -1.330500, 2.877640, 0.732370, -1.909150, -0.092420,
-0.499890, -0.707070, -2.698490, 0.106110, -0.001940, 3.483430, -0.792500, 0.017410, 0.767860, 0.831500,
1.005740, 1.311250, -0.197180, -1.383780, -0.462260, 2.014690, 0.152830, 0.429730, 1.473820, 0.217560,
1.165040, -1.154970, 0.035280, -1.949960, 0.374300, 0.295130, 0.756760, -0.934770, 0.183450, -0.007030,
-0.038490, -0.641590, -0.538570, 2.650290, 0.126610, 0.325110, 3.026680, -0.377610, -0.596360, -2.397420,
0.287760, 2.707930, -2.020340, 0.295140, -1.130330, -1.785280, -0.225560, 0.351520, -0.324600, -0.243980,
-0.150520, -1.363000, -1.045650, 0.654200, -1.452420, -0.216450, -1.151280, -0.332390, 0.119830, -0.593200,
-2.276680, -2.446380, -1.798000, 0.673980, 1.547630, -0.799970, 2.434800, 1.211990, 0.694570, -0.725990,
1.906400, 0.217270, 1.190720, 1.142510, -0.296060, 1.060370, 1.217140, 0.279410, 0.006070, -0.424380,
0.497510, -0.400000, -0.024380, 0.505890, 1.444360, 0.314970, 0.563230, -0.151890, 1.051840, -0.084920,
-0.899030, -0.034510, -0.932470, -0.446420, 0.309800, 0.663580, 1.813450, -0.035460, 0.320430, 0.209520,
-1.087290, -0.427690, -1.892070, -0.194850, -0.473570, 1.914780, -0.335600, 3.425330, 1.286470, -0.761600,
0.004530, -1.078250, -0.919420, -0.153840, -1.182830, 0.356050, -0.354570, 0.687580, -1.848430, -0.064710,
-0.730450, -0.411000, -0.685990, 0.669760, -0.369250, -1.063990, 0.878820, 0.146240, 0.671410, -0.665660,
-0.649590, -0.796870, -0.379130, -1.015220, 1.401550, -0.942000, -0.949790, 0.583450, 0.052950,
0.547790, 0.238680, 0.383260, 0.379440, 0.360300, -0.386170, 0.923420, -0.550330, 0.996900, -0.481080,
-0.217090, 0.548630, -0.844480, 2.507970, -0.063920, 0.014320, 0.495190, 0.028400, -0.285060, -1.236460,
1.416920, -0.230620, 3.567070, 0.767220, 0.099230, 0.258640, 1.004990, 0.263170, 0.915320, 0.233400,
-0.154120, -0.357800, -0.058570, -1.132960, -0.889520, 0.291420, 0.576000, 0.423050, -1.020130, 0.302450,
-0.948750, -2.119580, 0.348400, -0.469000, 0.235990, 2.310750, 0.103060, 0.350210, -0.093730, -1.633020,
0.145190, 0.679140, -0.902770, 1.685410, 0.586780, -1.676270, -0.565810, 0.151880, 0.124270, 1.131150,
0.418030, 0.634990, 1.064150, -0.204890, 0.539200, -0.027540, 0.761600, -1.043900, 1.393240, 0.119080,
0.368490, -1.081070, 0.571560, 0.494870, -0.122390, -0.074240, 0.230070, -0.440810, -0.010210, -0.229620,
0.460940, -0.205750, -0.131080, 0.122680, -0.743240, -0.049230, -0.755660, -0.385010, -0.140140, 1.717600,
-0.042760, 0.326180, 0.348730, -0.913780, -0.156540, -0.174310, 1.339900, 0.175640, -0.715490, 1.554490,
-0.470300, 1.014790, 0.111430, -0.250890, 0.098770, 0.726020, -0.685040, 0.895940, 0.705340, 0.144430,
0.031020, -1.195520, 4.055720, 0.390360, 0.319930, -0.594650, -1.733290, -0.245880, 0.242510, -2.017050,
-0.525020, 1.573900, 0.022870, -3.129090, -2.699260, -0.779130, -1.345950, 0.177160, -1.333050, 0.375110,
0.456880, -0.393100, -3.926200, -0.485680, -0.165750, -8.142260, -0.151590, 5.745670, -0.544710, -0.147400,
-1.062320, 0.704250, 0.381370, 1.221140, -0.565820, 0.552910, -0.441750, -0.287420, -1.323770, -0.161550,
0.068290, -1.022910, -0.105450, -0.066810, 0.075890, -1.050870, 0.051870, -0.896520, 0.032500, 0.699030,
3.154430, 0.907190, -1.170970, -0.653140, 0.381260, 1.221380, 2.440730, -0.395320, -0.148830, 1.612130,
0.940320, 0.317970, -0.552260, 1.948190, 0.303620, 0.442770, 0.201590, 0.915720, 0.831900, 0.232090,
0.769710, 0.011630, -1.229260, -0.722660, -0.233230, -1.157430, -1.088970, 0.997280, 0.493610, -0.253860,
-0.845140, 1.926320, 1.255160, 0.033500, 0.690180, -0.377390, -1.258040, 1.743410, 0.341420, 0.415480,
0.135770, -1.443260, -1.674680, 0.047820, -0.373060, 0.533810, 1.939180, 1.873280, 0.599910, 0.791540,
0.140700, -0.084520, -0.412640, -0.220200, -0.051990, -0.351120, -0.756980, 0.567350, 0.467720, 0.220030,
0.297510, -0.068110, -0.662920, 1.137740, -0.777030, -0.549500, 0.481180, -1.126330, 0.511890, 1.042720,
0.999090, -0.516800, -0.362790, 1.203650, 0.814450, 0.591870, 0.059740, 0.643000, 0.076190, 0.410440,
0.422930, -0.226650, 1.221640, 2.150710, -0.053800, -0.103560, -0.411450, -0.583380, 1.140870, -0.427670,
0.770680, 0.472210, 2.940350, 4.011990, 0.298240, -1.682440, 0.744040, -0.200330, -0.075770, -0.172380,
1.403970, 0.097710, 2.418640, 0.794080, -1.936610, 0.642390, 0.225070, 0.741310, 0.720680, -0.520690,
0.741720, -0.249860, -0.250300, -0.036980, -0.257790, 0.136550, 1.310410, 0.519880, 0.890620, 0.481710,
-0.185380, 0.716590, 0.061290, 0.616330, 0.952040, 2.055820, -0.282730, 0.205510, 0.941970, -0.159530,
0.190710, 0.848600, -0.257330, 1.093590, -0.605870, -0.119660, 0.183860, 0.580480, 0.914890,
0.092620, 1.039370, 0.225580, -0.263400, 1.041070, -0.095020, -0.368830, -1.669620, 0.172340, -0.884870,
1.522520, -1.234550, -0.416240, -0.171820, 0.835240, 0.061030, -0.122020, 1.360520, -0.088340, 1.100530,
-0.497330, 0.411380, -6.507960, -3.177830, 0.821940, -1.417960, -0.243410, -0.456270, 0.616320, 2.294350,
0.223530, -1.348440, 0.523790, -0.827230, 0.695180, -0.126300, -2.066730, 1.094730, 0.822450, 0.450180,
-1.459030, -0.131570, 0.398940, -0.365830, -1.328520, 0.037300, -0.086140, 1.348530, 0.548890, -0.285700,
-0.475420, -1.155300, 1.354830, -0.258480, 0.247260, 0.689460, 0.326390, 1.089060, 0.024560, -0.100650,
-0.305980, 1.106460, 0.278230, -1.876950, 1.660790, 0.815310, 0.332680, 0.209970, -2.839520, 0.464560,
-0.400580, -0.790240, -0.092190, -0.891620, 0.563720, 0.462360, 0.465540, 0.127590, -0.703850, -0.431800,
-1.819000, 0.263640, 0.631980, 0.237930, 0.126910, -1.377080, -0.995780, -0.789200, -0.904430, -0.918470,
-0.628880, -0.404800, -0.790920, 0.408460, 0.081350, -0.568440, 0.356510, 1.141580, 0.713910, -0.373910,
0.795960, -1.348950, -0.443270, 0.072870, -0.277720, 1.146110, -0.570780, 1.671130, -1.316800, -0.175720,
-0.817690, -0.016860, 0.196910, -0.704280, -5.333970, 0.911890, 1.089350, -0.452380, -2.775980, -0.473060,
-0.128150, -0.639940, -0.591680, 0.118170, 1.426810, -1.005970, -0.119720, -0.536010, 0.113510, 0.746590,
-0.231030, 0.379630, 1.156700, -2.226490, -0.948370, 3.742240, 1.663730, -6.478430, 0.422610, 0.240270,
-1.080040, 0.199880, -1.179080, -1.417860, -0.937990, 0.130110, -0.097500, 0.287660, 0.895920, -0.135210,
-0.366890, 0.171460, 0.607290, -1.172030, 0.841930, 0.590630, 0.595470, -0.060030, 0.661650, 0.235750,
0.074430, 0.268190, 3.381240, -2.482570, -0.513350, 0.575730, 0.093650, -0.411770, 0.053070, -0.237290,
0.037010, -0.881960, 1.631240, 0.450490, 3.647580, 0.838440, -0.515810, 0.009660, 3.403160, 0.026550,
0.943630, -0.200680, -0.801390, -5.406870, -0.231560, 1.339790, -1.195150, -0.399250, -0.346230, 1.349820,
0.411020, 1.128880, -0.019500, -1.171830, 0.571280, -0.382790, 0.286200, -1.622210, -0.175030, 1.415240,
0.574760, -0.425880, 1.697580, 0.923080, -0.174620, 1.371720, -1.684510, 0.367530, 1.624180, 0.997400,
-2.392710, -1.033140, 1.040780, -0.336230, 0.526370, 0.250050, 1.593240, -0.810420, 0.336070, 1.256110,
-1.884470, -0.127030, 2.484220, 0.156040, 0.851020, 0.772710, 0.052110, 0.470100, -0.064610, -1.119310,
0.109580, 0.352210, 0.468030, 0.128450, -0.487320, 1.128950, 1.881020, 0.860870, -0.032590, 0.527920,
1.486790, -0.141450, 0.427090, -0.042190, 0.269270, 0.090970, -0.089840, 0.716170, 0.007450, -0.083210,
-4.006550, 0.005880, 0.798400, 6.965540, 0.942370, 3.922090, 0.548330, 1.154630, 1.905830, 1.552160,
0.643810, 0.851760, -0.106560, -0.404640, 3.085990, -1.763820, 0.966260, 1.035180, -0.928030, -0.792740,
-0.463910, -1.360540, -0.472660, -0.102330, -3.544440, -0.118020, -0.717140, -0.421570, -1.448070, -1.632880,
-3.636100, -0.285590, -1.452750, 0.128010, 0.031830, -4.429670, -1.539460, -0.903770, -0.941950, -1.015030,
-1.412520, -2.502650, -1.956490, -0.202530, -0.821680, 0.066940, 0.143980, -1.200640, -0.730950,
-1.490600, -0.384590, -0.439700, 0.037070, 0.695160, 0.728530, -0.985290, -0.956300, -0.043420, 0.087250,
0.614920, 0.115560, -0.204900, 0.475380, 0.613660, 0.246450, 0.569390, -0.608830, -0.676300, -0.167770,
0.463040, 0.660240, 0.456660, -0.041180, 0.292660, 1.358280, -0.116190, 0.721520, -0.005500, -0.693220,
0.657510, -0.331640, -0.226630, -0.354830, 0.806550, -0.428890, 0.522650, -1.125250, -0.306200, -0.835120,
0.214040, 0.999130, -0.920670, -0.534720, -1.236380, 0.189450, 1.310350, -0.546420, 0.616810, 0.048950,
-0.175550, 0.935140, 0.063620, -0.210300, 1.219170, -0.140670, 0.375340, -0.117340, -0.514770, -0.805750,
0.452060, -0.052650, -1.176480, 1.170430, -0.436560, -0.574290, 1.059600, 0.104480, 1.706370, 0.529610,
1.268220, -0.822970, 2.350340, -0.031410, -0.426170, 0.164090, 0.835630, -0.170380, -0.783440, -1.200470,
0.895150, 0.283660, -0.753550, -1.100770, -0.759880, 0.010780, -0.789070, -0.083000, 0.830490, -0.234540,
-2.144430, 2.894040, 0.751780, 0.433860, 0.280530, -0.427850, -1.417820, 0.626800, -0.560530, 0.149830,
-0.438540, -1.478140, -0.389030, -0.946670, -0.691310, 1.069200, -1.380280, 0.600260, -2.212760, -0.183870,
1.773600, -0.038080, -0.546130, 0.735810, 1.383840, 0.832740, 0.106990, 0.363880, -0.510420, 1.000030,
0.450230, -1.226140, 0.467510, -0.922440, 0.454340, -0.087810, -0.126400, 0.463850, 0.585340, 0.266200,
0.728230, -0.215600, 1.196400, 0.924030, 0.336470, 4.896490, 1.789220, -0.424160, -1.075330, -0.200780,
0.643710, -0.637610, -0.359010, -0.219280, -0.723890, 0.961110, 0.706370, -0.379950, 0.355210, -0.302660,
-0.126710, 0.138280, -0.079770, 0.826130, -0.355110, -1.266390, 0.651630, -2.276260, 0.405400, 0.526090,
-1.176280, -0.237080, 0.669890, -0.428530, -1.485620, -0.842800, 1.108570, 0.404070, -0.616380, -1.399470,
-1.277430, 0.828170, -0.166470, -0.318870, -0.851410, -0.461820, -0.068010, 0.016860, -0.740830, -0.241760,
1.439280, -0.204130, 1.188400, 0.283480, -0.155460, 1.068080, -0.304190, -0.493790, -1.765940, 0.054010,
0.103180, -0.143810, -0.409070, -0.818480, -0.527700, 0.090960, -0.938950, -0.948830, -1.005520, -0.985100,
-0.036180, 0.050210, 0.012810, 0.138250, -0.956890, -0.473020, 1.275810, -0.841690, -1.096760, -0.524810,
0.000930, -0.763750, -0.310980, 0.120620, 0.882680, -1.402690, 1.850880, -0.299580, -0.279090, 0.034490,
-1.689240, 0.494070, -0.355390, -0.536130, -0.028850, -2.301510, 0.264200, 0.255190, 0.329630, -0.890470,
-0.184360, 0.260310, -0.774340, -1.044400, -0.853430, -0.950690, -0.183580, 0.037680, -0.317320, 0.530680,
-1.130550, 0.175290, -0.798590, -1.631130, -0.292420, 0.484710, 0.800820, -1.251360, -1.237310, 0.790570,
-0.444280, -0.617910, -0.614300, -5.231660, 0.042440, 1.079460, 0.009740, 0.451470, -0.369440, -0.308250,
0.745030, -0.425250, -0.710490, -0.482980, 0.034410, 0.024580, 0.062420, -0.143940, -0.223830, 1.550590,
0.267280, 0.498380, 1.476530, 1.257920, 0.142490, 0.909540, 0.851320, 0.460950, -0.267760, -0.542920,
1.164480, 1.620210, -0.913440, 3.575770, 1.381560, -4.353970, 1.020500, 0.868670, 0.006480, 0.266340,
1.037140, 0.505410, -0.571190, 0.558640, 1.428570, 1.044860, 1.741980, -0.382170, 1.249240,
-0.159540, 1.804540, 1.062840, -0.532270, -0.117400, -1.261850, 1.172210, -1.251040, 1.321560, -1.576660,
0.459900, -0.743180, 0.922050, 1.064190, -0.092240, 0.371810, -0.350440, -1.721470, -0.332480, -0.083900,
2.697860, -2.223270, -0.931180, -0.508900, 0.317250, 0.390440, 0.544950, -0.772910, -0.604060, -1.444700,
1.410100, -0.870500, -1.355260, -0.240000, 0.217740, 0.812070, 1.609060, 1.054950, -0.133950, -0.709680,
-0.317510, 0.791520, 0.262770, -0.774570, -0.906950, -0.127640, 0.049020, -0.441170, -1.431930, 1.005170,
-0.869450, 0.326480, -2.647940, -1.084770, 1.663470, -1.495280, 0.138590, 1.558490, 0.287700, -0.204700,
-0.499920, 0.668320, 0.126560, 0.230830, 0.577170, 1.404090, 0.343960, 0.994560, 0.235010, -0.722170,
-0.138300, -0.645420, -0.122570, 0.777320, -1.149460, -0.016720, -0.787860, 0.193880, -2.005440, 0.941620,
-0.485760, 0.385780, 0.097290, 0.226500, 0.478470, 0.574980, 1.460800, -0.862140, 0.569780, 0.482630,
0.358880, 1.258220, 0.172510, -2.585140, -0.530030, -0.712500, -0.003860, -2.531030, -1.835690, 0.364990,
-0.370900, -0.973930, 1.778880, -0.002020, 0.792610, 0.469910, 0.131220, -0.941620, 0.865140, -1.764410,
1.403630, -1.393400, -0.625320, -0.283210, -0.876630, -3.229730, -2.828960, -3.174730, 3.238140, -6.423820,
-0.264020, 2.651070, -1.195700, -0.833030, -2.319120, -0.422960, 2.205050, -0.414770, -2.981750, -0.666210,
-2.939600, -0.249740, -2.760830, -1.486150, 1.190050, -2.695570, -4.139940, -0.319070, -1.393510, -0.732970,
-0.404140, 1.089230, -0.359570, 0.477290, 0.059860, -0.044580, 0.268870, -1.049210, 1.737440, -0.686850,
0.492550, -0.444960, 1.348390, 0.252830, 0.630840, -0.863970, 1.100200, -0.260690, -0.612520, 0.435630,
-0.374870, -0.820820, -2.756430, -0.553760, -0.103320, 1.245820, 0.521530, 0.880880, -0.254160, -1.908730,
-0.023670, 0.001000, -0.295880, 0.638530, -1.905010, -0.524380, 0.043290, -0.171770, -2.492860, -0.417740,
0.068640, -0.644370, -1.775010, -0.296150, -0.950170, 0.054320, 0.109660, 0.300210, -0.156600, -0.249720,
0.123030, 0.681930, -0.201020, -1.294450, 0.056830, 0.681360, -0.220270, 0.249730, 0.680650, -0.093180,
0.827930, -3.439780, 0.850620, -0.084680, -0.616010, -1.162510, -0.118300, 0.788660, -0.544130, -2.040750,
0.078810, -0.209410, 1.047740, 0.622200, -0.100730, -0.825870, -1.584240, -0.033430, -1.811790, 0.646160,
-0.142900, -0.798970, 0.329180, -0.073240, 0.093500, 0.984140, 0.622170, -2.211120, 0.550110, -1.279990,
-0.425940, -1.311510, 0.347650, 0.007060, 0.655050, 0.562380, 0.322130, -1.240140, -0.863890, -0.189740,
-0.377290, -1.195470, -0.007250, 1.118610, 1.808540, 0.757310, -1.080150, -2.086170, 0.475390, 0.323180,
0.134580, -0.134880, 0.442510, -12.351920, 0.153140, -0.287070, -0.670420, -0.499830, 0.423540, 0.406490,
0.750700, 2.133660, 1.538790, 0.064860, -0.145980, 0.792240, -0.368960, 1.052090, 0.096400, -2.235630,
-2.313050, -0.935660, -3.504310, -1.923270, -2.628210, 0.248570, -0.216560, -1.121090, 1.473290, -1.145610,
0.089790, -0.486660, -1.070730, -1.979560, -3.360100, -0.115640, -2.316010, -0.320100, -0.553630, -0.096630,
-0.860280, -0.482170, -1.109860, -2.714180, -2.128100, -2.504570, -2.545860, -0.679910, -2.247840,
-2.000110, -2.330160, -0.369890, 0.720320, -0.441580, -0.072910, 0.898150, -1.312670, -0.095510, 0.250370,
-0.630870, 1.217210, 0.611660, -1.383330, 0.588590, -0.451060, -0.308210, 0.442620, 1.247380, -0.903470,
-0.501830, -0.999900, 0.185500, -1.679800, -3.505430, 0.279740, 0.145480, 0.217960, 0.555270, 0.692940,
-1.345140, 1.561260, 0.193110, 0.100460, -1.420540, -2.388320, -1.361880, 1.488470, -1.045310, -0.725360,
-1.438970, -2.366040, 0.492260, 0.522940, 1.346830, -1.148110, -1.584930, -0.621650, -0.659810, -0.039070,
0.323840, 0.093650, -0.725300, -0.834640, 0.268700, -1.173350, -0.489170, 3.009750, -0.565980, -0.526190,
0.939020, -0.256770, -0.247330, -0.575640, 0.195390, 0.863930, 0.683390, 1.816600, -1.225610, 1.153140,
-0.333490, 0.178090, -0.365110, -0.977530, -0.141670, -2.385830, 0.179580, 0.260010, -1.885680, -0.474750,
-1.080520, -2.004440, -0.237560, -1.292470, -1.462590, -0.932080, -0.065900, 0.724230, 0.102000, -0.717880,
0.866570, -0.944680, 0.248890, -0.756390, 0.700160, 1.653850, 0.118510, 0.252350, 0.224110, -1.537610,
0.434200, -1.103350, -1.922710, -0.594570, -1.726420, -0.335140, -0.215150, -0.311670, 0.454380, 0.110760,
-1.011110, -1.058280, -0.655140, -0.183140, -1.797510, 0.728770, 1.700880, -1.725660, -0.315060, 0.020360,
1.216510, -0.046640, -0.455220, -1.269690, -0.488620, 0.420460, 0.970090, 0.784690, 0.137340, -0.748600,
-0.866130, -0.683330, 1.715580, 1.077380, 0.289520, -0.303710, 1.203770, 0.249920, 1.582890, -0.283410,
1.584090, -1.060260, -0.095610, 0.493100, -0.122240, -0.760850, -0.070260, 0.168080, 1.286760, 0.673300,
-1.189460, 1.409950, 0.012080, -0.001380, 0.146980, -0.173350, 0.849040, -1.173580, -0.722210, 0.871760,
-1.538820, -1.810530, 0.489210, 0.448480, -1.972900, 0.395390, -1.237760, 0.330100, -0.098600, -0.763340,
-2.172510, 1.283070, -0.249820, -1.601510, 0.390490, -0.493330, -0.072070, 0.965420, 0.712760, -0.318960,
0.274200, 0.066010, -0.088170, -0.095660, -1.266710, 0.580680, -0.844470, 0.155030, -1.608530, -2.007090,
-0.261600, 0.433020, 0.418050, -0.649730, -0.438370, -0.594080, 0.996620, -0.865240, 0.937810, -0.253510,
0.298800, 0.440630, -0.133150, 0.650660, 0.467540, 1.485950, -0.878030, 0.911300, 0.537530, -1.904150,
-2.839470, -0.946350, -0.986010, -0.568500, 0.312310, 0.703750, 0.825020, -0.631210, 0.866110, -0.791540,
-0.139390, 0.149080, -0.961480, 0.219920, 1.966550, 0.132230, -0.901420, 0.920940, -1.350310, 0.602580,
-1.345550, -1.456270, -0.396510, 0.013390, 0.671200, 0.397270, 0.509600, -3.214110, 0.186790, -2.497290,
0.219850, 0.721340, -0.283860, -0.076660, -1.311060, -0.621870, 0.474940, -0.225360, 0.362920, 2.319400,
-0.926340, -0.253670, 4.733270, -17.577860, -2.840140, -0.788920, -0.855880, -0.716500, 0.240240, -1.351160,
-3.049940, -1.186390, 0.019440, -1.046090, 0.533700, -1.134510, -0.369380, -0.072220, -0.352230, 0.188160,
-0.762620, 0.121200, -1.014510, 0.418110, -1.647550, -0.729470, -0.382420, -0.370810, 0.356460, 0.802110,
-0.978840, -0.576130, 0.104340, 0.019140, -0.811230, -3.040580, 0.071830, -0.531660, 0.461820, -0.207660,
-0.984770, -0.453150, -0.448340, 0.616860, 0.044300, 0.341490, 0.433430, -0.478700, 0.949540,
0.723340, -0.362100, -0.943080, -0.090100, 0.360000, 0.408640, -2.018080, -1.506090, -0.435120, -1.591190,
-0.830110, 0.444060, 0.208380, -0.264490, -0.037690, -0.458400, -0.922460, 1.469460, 1.123090, -0.049550,
0.487460, 0.564620, -0.282250, 0.208450, -0.352570, -2.670970, -0.495110, 0.654610, -1.386370, -2.230730,
0.966870, 2.578670, -1.830490, 0.585880, 1.671540, -0.600440, 0.589230, 0.503610, 0.456230, -0.108960,
-1.221490, 0.584330, 0.481850, 1.162360, -0.326100, -1.694090, -0.836220, 0.168250, -0.638890, -1.040400,
0.563310, 0.565160, 1.164580, 0.755410, 0.326140, -0.723830, 1.803120, -0.478190, 1.744360, 1.560250,
-3.552840, -0.711990, 0.845430, -0.427740, -1.000990, 0.370430, 0.033250, 0.956450, 1.619060, -1.066490,
-0.217680, 0.738790, 0.823610, 0.468840, -1.484970, -0.061000, 1.173840, -0.384460, -2.409540, -0.126040,
0.566120, 0.358810, 1.333260, -1.218760, 0.280570, -0.269420, -1.158900, 1.613670, -0.222860, 1.692600,
0.731420, 0.772420, 0.399910, 0.151720, 0.658720, -0.285010, 0.099720, -2.093560, 0.154520, -0.235930,
-1.447910, 0.872770, 0.873170, 0.553040, 0.403420, 0.370570, -0.071300, 0.993490, 0.314980, 0.574730,
-1.385180, 0.883710, 0.663990, 1.196680, -0.593850, -1.719920, -1.907790, -0.538760, 0.951900, -0.269610,
0.598520, 0.821920, 0.333650, -1.627630, -6.080080, 0.915600, -1.155150, 0.700090, -0.069710, -0.337470,
-1.362480, 0.357560, -5.319420, -0.771210, 0.153490, -1.354290, -0.216120, 3.004870, -0.503230, 1.523840,
-0.494590, 1.236170, 1.643250, -1.620110, -0.319580, 1.264630, -0.481100, 1.626430, -0.679320, 0.011230,
0.423950, -0.870230, 0.504960, 0.627860, 0.976120, -1.272990, -0.674180, 1.314020, 0.766740, -0.124610,
0.245940, 0.636770, -0.253960, 1.257260, 0.104730, 0.558230, -0.396900, -0.191190, -0.564670, 1.098250,
0.342880, 1.922630, 0.688860, -0.178640, -1.089270, -0.693150, 1.055370, -1.515710, -0.504350, 1.073320,
-1.316590, -0.068200, -0.707090, 0.319620, 0.918920, -0.000480, -0.507010, -1.040020, -0.040660, 0.186830,
1.755100, -0.185680, 0.888640, 0.070340, 0.757700, 1.419010, 0.599730, -0.288780, 0.637240, 0.153400,
0.456400, -0.825210, -1.058720, 0.488320, 1.701200, -1.365880, 1.618740, -1.003820, -1.022010, -1.436970,
0.139710, -0.876040, 0.819840, -0.235250, -0.651050, -0.378790, 0.671670, -0.742860, -0.740620, -0.572130,
1.186390, 0.465990, 0.598890, -0.267530, -1.198650, -0.241020, 0.719650, 1.107960, 0.679750, 0.343800,
-0.045220, 0.022860, -0.043290, -1.828150, -0.274620, -0.724620, 1.714480, -0.675390, 0.679580, 0.805010,
1.182510, -0.073050, 0.587470, 0.913320, 0.270920, -0.645680, 0.778670, -0.198000, 0.624910, -0.796140,
1.171360, 0.435340, 0.155950, -0.655230, -0.255990, 0.038640, -0.760160, -0.896180, -1.622660, 0.256910,
0.773950, 0.502990, -0.647690, -0.322900, 0.405820, 4.813950, -0.174480, -0.350510, -0.751220, 0.618940,
0.455610, -0.059600, -0.565060, 0.563620, -0.441830, -0.140740, -1.335730, -0.947000, -1.115060, -0.279400,
-0.200020, 0.188120, -0.688660, -1.306450, -0.407660, 0.446990, -1.368160, 0.973650, -0.051230, -0.094830,
-0.877490, 0.877930, -1.023520, 0.090590, -0.692580, 0.398310, 0.105860, 0.129500, -0.184600,
-0.627990, -0.235910, -0.051450, 0.938380, 0.584300, -0.550200, -0.213980, -0.570960, 0.916160, 0.881070,
1.360140, 0.012260, -0.442430, -0.733840, 0.567550, 0.473460, 0.243920, 0.874970, 0.848440, -1.365950,
0.492390, -1.333820, -0.794100, 0.587000, -0.990550, -1.389410, 0.296740, 1.148980, 0.931950, 0.753990,
-0.786970, -0.779370, -1.738230, 0.420810, 0.881840, 1.323000, 0.790910, 1.024000, -1.684280, 1.201050,
-1.176720, 1.151280, -0.464360, 0.866570, -0.188910, 0.800070, -1.252560, 0.792270, 0.486740, 0.460020,
-0.117520, -0.814020, -0.984850, 0.053450, 0.227440, -1.229950, 2.012600, -1.554850, -0.236650, 0.718890,
-1.393820, -0.640830, 0.961060, 0.178780, 0.025180, 0.907400, -0.465530, -0.641580, 0.741920, -0.427310,
-0.561490, 0.744400, 1.042980, 0.477180, -1.522260, -0.780770, -0.793910, 0.250170, 0.913810, -0.544030,
1.118000, 0.625650, 0.594050, -0.716760, -0.078440, 0.796510, -0.094030, -0.391090, 0.428460, 0.172440,
2.331600, 0.066400, 0.084130, 0.807280, -0.301160, 0.732040, -0.132840, -0.577430, 0.174980, -0.589670,
0.827050, 0.601290, 0.070630, 0.558420, -0.013660, 0.749920, 1.362460, 0.319420, 1.230900, 1.471690,
0.013500, -1.147600, -1.189940, 3.001930, -0.038250, -3.155690, -1.948670, -1.789040, 2.287470, -3.251110,
0.556910, 3.069080, -0.434220, -6.370560, -4.164510, 2.600890, 3.343190, 0.363590, -0.659510, -1.338610,
0.963910, 1.547880, -3.932830, 0.201030, 3.609120, -1.335460, 1.603310, 1.243680, -0.252880, -0.239440,
0.502490, -0.354410, 1.039940, 0.672410, 0.334890, 0.800660, 0.224950, 0.753400, 0.441820, 0.231940,
-0.093830, -0.052100, -0.124270, 2.372730, -0.630900, 0.919830, 0.494040, 0.863980, 0.666250, 0.623690,
-0.216650, 0.434960, -0.751700, 0.935270, 0.454850, 1.543260, -0.843810, 0.148280, 0.359860, -0.045200,
0.069250, 1.057160, -0.331850, -0.325760, 0.128840, -0.273350, -0.049380, 0.000560, 0.277510, -0.400300,
-0.043780, -1.154550, -1.265740, 1.085000, 0.258920, -0.010850, -0.001390, -1.594400, 0.150400, -0.653090,
-0.002120, -1.257020, -1.102530, 0.131560, -0.813730, -0.295770, -0.715430, -0.279040, 1.648180, 0.235360,
0.943680, 0.793200, 2.311010, 1.543440, 0.052240, -2.386860, -0.208410, 1.649180, -0.207990, 0.200640,
0.666430, 0.568690, -0.316970, 0.023520, 0.341600, -0.388540, 0.727940, -1.091870, 0.887500, 0.791650,
0.596950, -0.332990, 0.964440, 1.169300, -0.487420, 0.640500, 0.246350, 0.415270, 0.717450, 0.661880,
0.646650, 0.197870, 0.942060, 0.626840, 0.141630, 0.674590, 0.361310, 0.089530, 0.402090, 1.746940,
-0.119150, -2.181510, 0.892740, 0.351450, -0.375290, 0.795080, 0.629780, -0.354830, 0.235770, 1.488180,
0.291240, 0.314220, 0.454330, 3.046260, 0.068270, 0.845190, 0.273530, 0.853770, 0.188160, -0.641690,
-0.029640, -1.135120, 6.332080, 3.280850, -0.493220, 0.343790, 0.333060, -0.045190, -0.266680, -0.138320,
-0.861830, -0.929250, -1.044840, -2.380510, 1.479450, -0.262570, 0.755470, 0.082740, 1.233560, 0.826420,
2.196470, -0.692460, -0.721100, -0.525040, -2.184570, -1.442700, -0.237600, -0.275490, 0.124110, -0.302750,
-0.171690, 0.223370, -1.300720, -1.055520, -0.194990, -1.226710, -0.323070, 0.763970, 1.229780,
1.091900, -0.069020, -1.411200, 1.261030, -0.804800, -0.203840, 2.121730, -2.535720, -0.773090, 0.275250,
1.047370, 1.089400, 0.514460, 0.280160, -0.806310, 0.114440, -0.918370, 1.296990, -0.626280, 0.392070,
2.153650, -0.882410, -3.326330, -0.752860, 1.603040, -0.692050, -2.031240, 0.374630, -1.127040, 1.186720,
0.845190, 0.580740, 0.388610, 2.135830, 0.123560, 0.092370, 2.265880, -0.551190, 0.196190, 0.890320,
-1.150670, 0.564880, -0.917100, 0.143800, -1.429190, -0.276120, 0.822230, -0.765660, -0.626360, -0.399920,
-0.263190, 0.282430, -1.205010, 0.339980, -1.026140, -1.802510, 0.172860, -0.931440, 0.592920, -0.998360,
-0.211840, -1.078420, 0.369010, -1.935740, -0.218960, -0.510800, -0.212280, -0.339710, -1.171630, -0.460960,
-0.636710, -0.545240, -2.039310, -0.703190, -0.123160, 1.827220, -1.843190, 1.637310, -0.828140, 0.024060,
-0.619920, -0.530500, 1.558550, 0.274080, -0.183310, 1.944870, 0.189290, -0.552900, -0.933390, 1.514700,
1.285780, -1.611500, 2.724140, -1.598930, 0.837520, -0.756370, -0.227730, 0.279340, -0.768620, 0.347350,
-1.256890, -0.307510, -1.085660, 0.536070, 0.759080, 1.828310, -0.771330, -0.012600, -0.217010, -0.259380,
-0.082080, 0.415310, 1.312150, 0.954850, 0.107000, 0.836360, -3.001490, -1.571650, 0.343740, -0.369490,
-1.297920, 1.755550, -0.313460, -2.172130, -1.180130, -0.509950, -0.620490, -0.201290, -2.860060, -0.876460,
-0.860080, -1.103050, -4.938820, -0.274830, -1.485730, -7.676190, -0.608480, 2.555780, -2.685480, -1.633730,
-0.763070, -0.286780, -0.272510, 0.073100, -2.088190, -0.499400, -4.049490, -1.095640, 0.506250, 1.460860,
-1.424510, -5.710550, 0.584980, -0.566540, -0.043650, -1.747310, -0.183970, 0.912520, -0.106430, -2.146760,
0.286010, 0.210010, -1.979510, 0.713340, 1.047180, -1.566630, -1.809530, 0.510330, -4.034800, -1.572010,
-0.259370, 0.621130, -1.108880, -1.154590, -2.261950, 0.475680, -0.205650, -0.069840, -1.713300, -0.733510,
-0.740620, -0.666050, -0.914970, 0.883330, -1.788360, -1.125600, 0.504180, 1.450960, -0.986250, 0.522100,
-0.823310, -0.251070, -0.626960, -0.068690, -1.719840, -0.724810, 0.105060, 0.197350, 0.222340, -1.308170,
0.261020, -2.928700, 1.745050, 0.143240, 0.377970, 0.021220, 0.284060, 1.803450, -1.281250, -0.480410,
-1.274640, -0.708840, -1.166360, -0.568560, -1.508790, 0.065590, -0.801050, -0.452560, -0.304410, 1.904310,
-0.439370, -0.983330, 0.357900, 1.084680, -0.246500, 1.112710, 0.922670, 0.251950, 2.266450, -0.997880,
-1.059550, -0.195800, -0.299010, -1.926980, 0.514030, -0.441460, -0.649930, -2.340270, -0.071790, -1.055370,
-0.545830, -0.075160, -1.041560, 1.741900, -0.027410, 0.273710, -0.377270, -0.702860, -0.266820, -0.150910,
-1.357770, -1.125190, -0.728640, -27.273310, 0.893120, 1.135510, -0.815630, -1.590510, -0.435590, 4.301960,
1.450290, 0.730820, 4.084750, -0.074570, -0.684120, 0.406680, 0.636660, 1.279390, -0.597390, 0.025170,
0.584930, -0.233300, 0.472790, 0.799890, 0.865880, -0.258370, -0.649710, -1.046760, 1.243210, -0.476280,
1.014730, -0.615960, 0.088620, -0.615770, -0.091450, 1.725130, -1.167910, -0.319960, -0.103660, 0.226420,
0.635320, -0.094190, -0.726430, -1.031820, -0.249930, -0.460800, 0.288030, 0.194730, -1.050300,
-0.356980, -1.914160, 0.022570, -0.624050, -0.092430, -1.165110, -0.158080, -0.415510, 0.160080, -0.340540,
0.185050, -2.424130, 0.545000, 2.253000, -0.326570, 0.905120, -0.902780, -1.398580, -0.858440, -0.317820,
-0.174430, -0.723030, 0.519440, 1.257000, -0.026230, 0.253440, 1.480570, 0.905790, -0.929030, 0.082710,
-0.314060, 0.610720, 0.504990, 0.772360, -0.925540, 1.497140, 3.442810, 0.680540, 0.971790, 0.619880,
-0.247420, 2.467780, 5.081180, -0.871500, -0.245760, 0.382850, 1.921390, -0.187290, -1.548640, -1.000010,
-1.962240, 0.338500, -0.350990, -0.982920, -0.063960, -0.143980, 0.006280, 1.553290, 0.493630, 0.840460,
0.348690, 0.234660, -0.301620, -4.952400, -0.603210, 0.447340, 0.980780, 1.181090, -0.829340, -0.626480,
0.591940, -2.169370, 1.393150, 1.401580, 2.290930, -0.448450, 2.085060, -1.764670, 0.720560, 1.729290,
0.000780, 0.532640, 1.499470, -1.019740, 1.937490, 0.459630, 1.717200, 0.124330, -0.365090, -0.228340,
-1.150750, 0.428280, 2.202780, 1.333680, 0.610550, -2.813930, 2.307720, 0.243810, 0.855480, -0.028020,
0.137020, -0.637620, 0.161980, -0.097210, 0.515890, 0.540090, 1.330360, -0.470920, -1.137070, -0.902820,
0.640960, -0.671480, 0.585940, -0.875970, -0.356700, 0.154670, 0.585230, -0.276260, 0.082830, 0.666220,
1.280980, 1.071470, 1.153130, -0.897380, -1.236320, -1.004750, -0.088270, 3.988970, -0.381110, 0.289720,
3.961400, -0.499130, -0.606170, 1.034870, 1.260820, -2.990010, 0.925130, 0.401390, -1.623090, 2.923050,
-0.221750, 0.418000, -1.983560, -1.927540, 1.092230, -0.046220, -1.506630, -0.734330, -1.684370, 2.598270,
0.928200, 0.179160, -0.021060, -0.602110, -0.562690, -0.119920, -1.102930, 0.969700, -4.228380, 1.036820,
-2.630290, 0.324340, 0.174400, -0.000780, -0.535140, 0.219760, 2.116240, 0.342960, 2.802990, 1.509280,
-0.826170, 1.197180, -0.808490, 0.329430, -0.556250, 1.437690, 1.772280, -0.201130, -2.763840, 1.105750,
0.047300, 0.251160, -0.288130, -1.080390, 0.096020, -0.649830, -0.002420, -0.531870, -1.404370, 2.411840,
-0.137170, 0.980600, -0.818250, -1.117030, 0.424450, 0.939370, 0.017130, 0.965340, -0.357060, 0.793460,
0.020280, -1.733540, 0.789450, 0.169070, -1.284450, -0.453420, -0.790010, 0.891260, -0.071920, 0.013060,
-0.159290, 0.430610, 1.423290, 0.182350, 0.060090, 0.141430, -0.307470, 1.561190, -2.027040, 1.527730,
0.707040, -0.303890, 1.158650, 0.948480, -1.898630, -0.254240, -0.296280, 0.007050, 0.300000, 0.877510,
-0.449460, 0.932180, -1.136110, 0.645450, -0.777030, -0.508180, 1.215580, 1.900850, -1.699930, 0.096570,
-0.717280, -0.277410, 1.917180, 0.615780, -0.730410, -0.348340, 0.587610, -0.172870, -0.465640, 0.245270,
-0.416530, -0.776090, -0.814700, -8.499570, 0.923190, -1.120930, -0.257380, -1.144470, -0.358560, 0.534350,
1.904060, 0.771590, -0.406560, -0.663840, 0.040840, 0.617810, -0.597370, 0.816850, -1.131220, -0.572030,
0.630770, 1.723990, 1.296540, 1.090000, 0.791180, 0.259330, 1.272550, 1.119770, -0.629620, 1.374690,
-2.971080, -0.073730, 0.252130, -0.341430, 0.096930, -2.157080, -0.044220, 2.746220, 1.223660, -0.985920,
0.384220, 0.493930, -0.526840, 0.212420, 0.868880, 0.589210, 0.053050, -0.332660, -0.190870,
-1.370720, 0.162090, -0.634210, 0.045300, -0.470060, 0.305380, -0.175290, -0.003920, -0.076910, 0.059530,
-0.753980, -1.322050, -0.425250, 0.964200, -1.745740, -0.337030, 0.767950, -1.919440, -0.172910, -0.737070,
2.426370, -0.030340, 1.228640, 0.171160, -0.279020, -0.144550, -0.778270, 0.224940, -0.174530, -0.483780,
0.406890, -0.668360, -0.232730, -1.758810, -0.321440, -0.134030, 0.921310, 0.580720, 0.743820, 0.431230,
0.165670, 0.328430, -0.549910, 2.244110, 1.165470, -0.016120, 0.237860, 1.374710, 0.043220, 2.119960,
-1.097480, -0.243750, -0.002800, -0.881030, 0.204470, -0.385360, 0.131210, 1.917210, 0.344780, 1.140760,
0.187360, -0.789500, 0.167510, -0.853200, 0.213250, 1.351590, -0.261650, -2.216470, -0.835460, -0.235950,
2.071250, 0.740150, 2.039270, -1.031810, -0.825880, -1.126330, 0.747400, 0.051060, 1.096990, 0.193280,
0.535400, 0.893640, 1.024770, 0.479400, 0.379720, 0.790510, 1.493170, -0.970940, 0.044110, -0.086860,
-1.102820, -0.214930, -0.013870, 0.513070, -0.266540, -0.255600, -0.063090, -0.331030, 0.578830, -2.190260,
0.820730, 0.605330, 0.181050, -0.193440, -0.625540, 1.197970, 1.443160, -0.473470, -0.061090, -0.385560,
0.048720, -0.433860, 1.387990, -0.344460, -0.064840, -1.761440, -4.588810, 1.866640, -0.705670, -4.666170,
-0.936370, -0.103540, -2.179380, -2.250660, -4.104180, -0.334700, 0.244770, 1.711290, -2.064930, -2.002860,
0.974830, 0.179050, -9.055400, -0.720160, 1.185670, -7.608980, -4.900630, 4.242910, -0.227840, -0.956180,
-1.923920, 0.121230, -1.305950, 0.241710, 0.012400, 0.853910, -1.310500, -3.573770, -0.064270, -1.060450,
-0.120350, 1.769860, 1.305960, -0.675690, -0.682660, -0.709210, -1.044630, 0.157410, 1.372020, 0.498970,
0.237360, -0.929110, -0.348920, -0.550110, 1.380030, 0.307650, -1.929040, -0.974570, -1.053590, -1.149660,
-1.405050, -0.652570, -0.623510, -1.563820, 1.476130, 0.430000, -0.276470, -0.755390, -1.525760, -0.411210,
0.348970, 0.181610, 0.603060, -0.749560, -0.320260, -0.341210, 0.234700, -1.563360, 0.180780, 0.844970,
-0.042060, -0.248540, 0.277000, 0.473210, -0.329660, -0.505070, 0.181550, 0.181380, -0.537170, 1.372400,
-1.044980, -0.263450, -0.033180, 0.602420, 1.812920, -1.464310, -0.785840, -1.561630, 0.949750, 0.037530,
-0.117010, -1.165410, 0.164150, 0.760230, 0.561220, -0.057290, 0.217210, 0.427470, 0.182400, -0.511790,
0.475880, 1.393840, 0.245360, -0.205470, -2.979320, -0.146880, 0.010220, -1.025900, -2.646810, -0.614470,
1.623730, -0.018080, -0.096820, -0.371640, -3.318080, 0.839380, -0.174120, -0.164630, -0.329260, -0.412680,
-0.324030, -1.322130, 0.413600, 0.520340, -0.859410, -0.634500, -0.520150, -0.954940, 0.000570, 0.985420,
3.129610, 1.115210, 0.998380, -7.410870, 0.121680, -0.748710, 0.668870, -1.333420, -1.370170, -1.830790,
-2.772260, 0.755170, 0.075460, 0.207490, -0.495210, -0.468560, -0.620410, 1.006140, -0.541940, -0.246410,
0.849320, 0.853880, -0.281540, -1.701570, -0.698030, -0.516550, 0.093630, -0.563700, -1.748320, 0.465410,
-0.089900, -0.893980, -0.224750, -0.094160, -0.385690, 0.822300, 0.013750, -1.018590, 0.091070, -0.526060,
-0.375790, -0.801750, -0.567330, 0.229970, 0.704170, 0.172440, -0.776030, 0.406580, -1.262260,
1.053640, -0.217220, -0.714610, 0.566950, -0.003370, -0.420900, -0.475580, 0.473340, 0.672430, -0.529320,
-1.211010, 0.313270, 0.120200, -0.756650, 0.296880, -1.053100, -1.320190, -1.536470, 0.632840, -1.084760,
2.351210, 0.926880, 0.210720, -0.790290, -1.062560, 1.989630, 0.579210, 0.477790, -1.486460, -0.909310,
0.888570, 1.905930, 0.395330, 0.105420, -0.545360, 0.169840, -0.107010, -0.015170, 0.234360, -2.209780,
-0.446700, -0.058200, 0.364870, 0.439080, -0.998480, 2.581120, 1.692440, 0.554860, -0.605220, -0.767590,
0.293470, 0.154530, 1.537130, 1.446110, 1.218070, -1.520790, 0.625140, 0.663710, 0.785190, -0.296850,
-1.001390, -1.202530, -2.643070, 1.154400, 0.874370, -0.969440, 0.310110, 0.326300, 0.065200, -0.717910,
-1.613280, 0.215620, -0.329650, 0.739520, 0.789920, -0.611730, 1.600970, 1.324080, 2.747250, 0.139580,
-2.371810, -0.631440, 0.649770, -2.160920, 0.838040, 0.116540, 0.480580, -0.610520, 0.442220, 1.567960,
-0.258160, 2.579530, 0.949950, -0.005760, -0.612670, 0.494970, -1.272960, 0.414100, 1.145990, 0.307890,
0.931200, 0.051320, 0.246800, 0.006430, 0.392670, -0.389440, 0.232300, 0.636020, 0.143030, -0.459810,
-0.198640, -0.732810, 1.374280, 0.447330, -1.451550, -1.065530, -0.315740, 0.199280, 3.282750, -0.308900,
0.257660, -0.581600, 2.304210, -0.448860, -2.056340, 1.435360, 1.353200, -1.303210, -0.489740, -0.785890,
-0.103000, 0.945550, -1.064600, 0.081300, 1.444590, -3.706540, -0.676490, 4.378610, 1.038670, -3.196550,
-0.040890, 3.619090, -0.443250, -0.278070, 0.164820, 1.649200, -2.142490, -1.382320, -0.475920, 0.867370,
0.845240, -1.469510, 0.934030, 1.684750, 1.009050, -0.701710, -0.661310, 0.875230, -2.833240, -0.011380,
4.720930, -0.557620, -2.683860, 0.735720, 1.188140, 0.592820, 0.344580, -0.090190, 0.700690, -2.444690,
0.009370, -0.146140, -0.224140, -0.773590, -0.913530, 0.411540, -0.463660, 0.864880, 0.655400, 0.335600,
1.586320, 1.478680, -0.464850, 0.899000, 0.380880, -2.476600, -0.839500, -0.448780, -0.043890, 0.577080,
0.276840, -1.635600, 0.681670, 0.460060, -1.395330, 1.589210, 0.630260, -4.469220, 1.964340, -0.722160,
-0.388730, -0.001190, 0.483400, 0.994700, -0.471400, 0.737990, 0.635820, -0.104710, 0.442970, 0.306430,
1.190210, -0.036390, -0.197320, 1.131960, 0.070910, -0.193720, -0.014830, 0.374710, 0.668380, 0.136740,
-2.008500, 0.219840, -2.111040, -1.022820, 0.179990, 0.863100, -0.222320, 0.388920, -1.173440, 1.322440,
0.826030, -0.889330, -1.125560, 1.723440, 1.749880, 1.182500, 0.497050, -0.523770, -0.257330, -1.202610,
-0.249910, 0.893690, 0.623350, -1.563760, 0.898550, 0.417120, -0.325010, 0.656110, -0.627450, 0.272040,
2.276850, -2.321760, -0.348020, 11.168400, -1.213920, -2.110490, -0.456490, 1.163600, -0.959520, -0.005000,
0.280440, -0.752610, 1.731370, 1.874020, -1.627840, 0.277250, 0.250580, -0.057540, 0.213400, 0.798310,
-0.247560, 0.928430, -0.502700, 0.010800, -2.373330, 0.777190, -0.535100, -0.887210, 0.600250, -0.466000,
-0.474640, 0.153540, 0.106250, 0.728050, -0.643180, 2.591100, -0.022690, -0.589900, -0.208890, 0.501790,
0.631680, 0.059120, -0.816740, -0.306590, 0.084280, -0.183330, 0.599350, -0.484770, -0.058240,
0.355610, -0.775830, -0.559270, 1.394590, -0.288140, 0.656670, -1.104360, 0.597450, 1.753890, -2.574940,
-0.435200, -0.648930, 0.659400, -1.743950, -0.211510, 1.270830, 0.299550, -0.548310, -0.746010, 1.318170,
-0.712970, 0.003890, 3.179570, -0.232220, -0.004580, -0.276860, -0.606500, -0.645440, 0.294910, -0.344650,
0.500030, -0.967760, -0.110040, 0.964400, 0.136650, -0.275780, 0.089590, -0.523940, 0.059140, 0.417100,
-0.732660, -0.821510, -0.674270, -0.119390, -0.302410, -0.328140, -0.831450, 0.656480, 1.390230, 1.974130,
1.768950, 1.297520, 0.688340, 0.201830, 0.091690, 0.701810, -1.420120, -0.074000, -1.316010, -0.923930,
0.757460, 0.008950, -0.994190, -0.228010, -0.194950, -0.544140, 0.509520, 0.001600, 0.081680, 1.636580,
0.505110, 1.388710, -1.640220, 0.511560, 0.181960, -0.909570, -3.236790, -0.516060, 0.577200, -0.262620,
-0.371080, -0.069020, 0.239470, -0.662300, -1.003150, -0.695860, 0.438270, -2.002980, -0.390710, 2.087200,
-0.890810, -0.900040, 1.499580, -2.146300, 1.265510, -1.024130, -0.164550, -0.184090, -0.883580, 0.782900,
-0.415610, -0.585100, -1.099130, 0.668410, -0.985970, 0.401970, -0.591780, -1.448690, -0.238510, -1.282030,
-0.510680, -0.916690, 0.350080, -0.234550, 1.005630, -0.679670, -7.609530, -1.084680, -1.163260, -1.288320,
-0.661930, 1.693720, 0.938630, 1.527670, -1.344840, 1.806620, 1.330790, -0.364560, -2.913560, -0.008860,
3.170700, 1.206540, -2.583010, 1.232800, 2.077390, -3.162030, 0.189210, 5.952030, 0.101220, 1.618300,
1.101760, 0.641840, 0.639700, 1.028980, -0.070590, 1.034370, 0.581100, -0.355570, 1.408230, -1.339340,
-0.665210, 1.762490, 1.547350, 0.824200, 0.329570, -2.553010, -0.519990, -1.236590, -0.064230, -2.081390,
2.702430, -0.417860, -3.478770, -0.104680, 0.619560, 0.572590, -2.838740, 0.275920, -0.876160, 3.352800,
2.063660, 0.206710, 0.629070, 1.448090, 1.009100, 0.785930, 0.208440, 1.177010, -0.267590, -0.870530,
1.965830, -0.148950, -0.867240, 2.583920, -0.825480, -0.509040, 1.463190, -0.184280, 0.456780, 0.348660,
0.118600, -1.381660, -0.212790, -1.070360, 0.025020, 1.028600, 0.408950, -0.542870, -3.233260, 0.669500,
0.695230, -1.023190, 1.384220, 0.251910, -1.958000, -0.774530, -0.017700, -0.612480, 0.764260, 1.451130,
-1.664230, -1.150320, -2.053900, 0.466760, -0.423450, 1.459200, -0.197370, 0.018650, 0.641670, -0.697320,
-0.299220, 0.383310, -0.788060, -1.255500, -0.031230, -1.172670, -0.619200, -0.518190, -0.484860, -0.839610,
0.740240, -0.628910, 0.079370, -0.928880, 1.309940, 0.315240, -1.963320, 1.843080, -0.029920, 0.311690,
-3.077910, -0.217290, -0.082180, 1.896140, -1.059080, 0.538550, -0.799880, -1.161240, 0.564700, -0.700260,
3.274650, 0.107850, 0.741670, 13.032150, -0.149150, -1.119660, 0.233270, -0.369390, 0.025870, 0.685460,
-0.707930, 0.490710, 2.681050, 0.676270, -0.996030, 0.487090, -0.144120, -1.629350, -0.847570, -0.733350,
0.328730, 1.584050, 0.493830, -0.517260, -0.698830, 0.067540, 0.457050, 0.919840, -0.772220, -1.119030,
-0.337360, 0.916970, -0.221270, 0.386620, 0.303320, 0.894830, 0.435730, 0.452980, -0.733040, 0.173230,
-0.614400, 1.473590, 0.209860, -0.258130, -0.643030, -0.898790, -0.562200, 1.001460, -0.717680,
-0.827190, 0.931810, -0.283040, -1.649790, 0.565660, -0.878500, 0.622310, -0.013870, -1.400020, -2.438500,
0.132430, -0.005160, -0.128020, -0.914210, -0.077030, 1.367530, -0.525260, -0.162500, -0.672100, 0.960170,
0.467270, -0.327830, -0.116090, -1.077510, -0.374660, -0.116960, -0.329700, 1.174920, -0.436250, -0.939520,
-1.442240, -0.102930, 0.061650, -0.810700, -0.417880, 0.591930, -1.282420, -0.872400, -0.595790, -0.349280,
-1.581310, -0.111460, -1.589810, -0.212100, 0.580470, -0.635030, -0.462340, -0.256030, -0.550300, 0.392110,
-1.825110, -0.638840, 0.588270, -0.822220, -0.412960, 0.816270, -1.287910, -0.157050, -0.444910, -1.096550,
0.594350, -0.223960, -0.348440, -0.452460, 0.795970, 1.309800, -0.876480, 0.477800, 1.054380, -0.992150,
-1.229560, -0.873910, -0.157200, -0.058590, -0.154840, -0.424740, 0.353440, 0.896220, 0.071840, 0.317630,
-0.064720, -1.046880, 0.484330, -0.897760, -0.881010, 1.401750, -2.926310, -1.055910, 3.564350, 0.028810,
0.506670, 0.665030, -0.501920, -1.069090, 0.248800, -0.990550, 0.027990, 1.565080, 0.428390, 1.231840,
0.858220, -1.054080, -0.272220, -1.366660, -0.358840, 0.832820, -1.027070, 0.010600, -0.927280, 1.730310,
0.447700, -0.361570, -0.838580, -0.077480, 0.737590, 0.069710, -0.033710, -0.194530, 0.099160, -1.118370,
0.544990, 0.093260, 0.474010, 1.591100, 0.694150, 0.315410, -0.116180, -0.812450, 2.899070, 0.003020,
0.767980, -0.860860, 1.596250, -1.876510, -0.195340, -0.336730, 3.190560, -0.698070, -0.241950, 0.206980,
1.449230, 2.489400, -0.928080, 1.337350, 0.620870, -0.309500, 0.496240, 1.565670, -2.665340, -0.503420,
0.640210, 2.260570, 0.315150, 0.504620, -1.437950, -0.641100, -0.237320, -2.938030, 0.137830, -0.289280,
0.288400, 0.145960, 1.314750, -0.180670, 0.791130, -0.131960, -0.645430, 0.862740, 1.295660, 2.280680,
-1.547980, 0.938880, -0.112430, -0.590300, 0.062150, 0.923020, 0.835590, -0.864350, -0.326520, -0.942490,
0.657010, 0.508930, 1.470800, -0.702480, 0.174670, 1.142970, 0.146120, -0.791310, 0.254600, 1.027610,
0.758730, 3.078320, 0.980250, 0.685210, 0.214520, -0.975850, -0.932500, 0.446060, 0.016730, -1.207760,
0.939170, 1.145910, -0.474010, -0.729460, -0.411400, -2.114850, 0.457090, 1.504410, 1.013400, 0.315140,
0.280350, 0.369220, 1.716230, 1.059300, 1.689470, 0.345740, -1.262210, -0.140510, -2.102930, -0.314880,
0.665270, 2.726350, -1.693470, -2.079670, 1.340690, -1.673830, -2.620730, -0.054340, -0.578430, -0.976840,
0.231950, 0.849670, 0.567850, 0.024280, -0.058000, 0.544440, 0.116230, 0.489150, 1.288700, 0.574580,
-1.855490, -0.431310, -1.027310, 2.443690, 2.019850, 0.170690, -0.196070, 0.130190, -1.841250, -3.592260,
0.422010, -1.069510, -0.254370, 1.904170, -0.774030, 1.256870, 0.663790, 0.062600, 0.674620, 0.792030,
-2.607930, -0.492170, -4.262430, -0.738280, 0.041150, -5.174790, 0.020960, -1.081840, -1.446670, -0.046670,
0.634520, 0.145780, 0.939170, 0.246370, -1.510460, -0.507750, 0.503760, -0.036530, -0.489010, 0.004750,
1.822070, -0.980240, -1.028970, -0.406880, 1.102810, 2.244110, -0.912670, -0.401640, 0.583570, 0.521740,
-0.636180, -0.474650, -0.716910, 2.544610, 0.575550, 0.804580, 0.517370, -0.551530, 3.816420,
-0.626480, 1.360570, -0.038300, -1.917260, 1.661920, -0.329910, -0.685730, 0.453030, -0.361790, -0.014180,
-0.328950, 1.228650, 1.653790, -0.214910, -2.331830, -1.135100, 0.290480, 0.889900, 0.243530, -1.021390,
0.819780, 0.464880, 1.257710, -0.922820, -0.204690, 0.229900, -1.257420, 0.955990, -0.124280, -0.367520,
0.275840, -0.592790, 0.647170, -0.599050, 0.575430, -0.542940, 0.682840, -1.886650, -0.810660, 0.985970,
0.724790, 1.469710, 1.056340, 1.131870, 0.007290, 1.962960, 1.448430, 0.329300, 0.613340, -0.299390,
0.175180, 1.136290, -1.527190, -0.827710, -0.824280, -0.869170, -1.266090, 0.203850, 0.783570, -0.042420,
2.007390, -3.085700, -1.867160, 0.216520, 0.944520, -0.391230, -0.958790, 1.345990, 2.503620, -1.154750,
0.001730, -0.698860, -0.226490, -0.277650, -0.838970, -1.255210, -1.100370, 0.356170, -0.199960, 2.851650,
2.290570, 2.811650, 1.434380, -0.631740, 2.763490, 0.511330, 0.197120, 2.125890, 1.313760, 0.112180,
0.903550, 1.984770, 0.344010, 0.351120, -1.234670, -1.073830, -0.694810, -0.553300, -1.214540, 1.384350,
-0.754770, -0.314800, -0.708100, -0.060030, 0.160920, -0.194240, -1.316700, 1.050640, -0.107360, 0.326080,
1.085850, -0.465240, 0.358230, -0.238120, 1.395740, -0.322080, -0.030610, -0.270430, -0.833880, 4.094130,
-0.440070, 0.691740, 1.154070, -0.619840, -0.651860, -0.999930, -0.629670, 1.198120, -0.562540, 4.055170,
2.126300, 0.820680, 0.645050, 0.274720, 1.449140, -0.443940, -1.067150, 0.832480, -0.826890, 2.331110,
-0.613840, 1.398970, -3.380410, -0.411310, -1.458170, 2.420330, -0.128840, -0.122730, 0.937250, 0.914290,
0.528330, -0.117320, -1.907490, 0.061070, -2.802250, -0.228670, 0.210950, -0.568650, 0.643930, -0.571400,
1.970620, 0.223470, -0.995970, 0.276220, 0.682710, -0.797150, 1.202390, -0.982020, 1.394030, 0.038780,
-0.104560, 0.128160, -0.056470, 1.179870, 0.451240, 3.002530, 0.310410, 0.658300, -0.983680, 0.392090,
-1.725020, -1.065380, -0.691660, 0.597330, -0.112140, 0.747980, 0.111620, 1.326540, 1.092080, 3.369290,
-0.036390, 1.433710, 2.100470, 0.657390, 0.387920, -2.733520, -1.007460, 4.863750, -0.213680, -1.521720,
-0.594710, 0.699730, -2.666560, -1.998030, 0.186140, 0.115710, -0.429550, -0.164790, -0.965490, 0.512890,
1.296960, 0.848000, 0.032470, 1.004080, 1.613460, 0.995600, -0.800790, 0.073490, -1.183760, -1.547310,
-1.907480, 0.703710, 0.017360, -0.897290, 0.098870, 0.800800, 1.536770, 0.907970, 0.012900, 0.022050,
-0.365130, 1.328280, -0.040900, 1.368360, -0.112030, -0.327770, -0.664330, -0.531550, 0.203460, 2.973950,
0.580960, 0.432520, -0.925990, 1.903280, -0.057500, 1.136770, -0.102410, -0.647210, 0.446600, 1.189180,
0.796390, 0.756930, -0.535840, 3.266170, 0.994890, -1.456020, -0.391210, -0.090280, -0.062630, 0.301090,
0.991530, 0.828690, 0.825290, 0.551350, 1.616440, 0.523850, 0.142950, 0.306090, 0.936080, 0.428870,
-0.535290, -0.490560, -0.002960, 0.969350, 1.808440, -0.338550, 1.267050, 1.408150, 0.841050, 1.981470,
0.806540, 0.117760, 0.277050, 0.800960, 0.264380, 0.181240, -0.931480, 4.347840, -0.839740, 2.920010,
-0.269380, -0.295510, 0.441760, 1.164880, 1.809840, 1.013650, 1.221390, 0.719370, 0.647020,
0.983110, 0.688810, 1.324190, -1.221190, 0.563810, 0.107540, 0.222350, 1.997350, -0.536340, 1.053360,
-0.621760, 0.543430, 0.416650, -1.360330, -0.422740, -0.063990, 0.371910, -0.946370, 1.309630, -0.750790,
-0.864930, 0.100550, -1.962560, -2.214940, 1.747410, 0.407110, 0.535050, 0.700960, 0.547360, -0.984940,
1.172680, 0.494990, 0.376070, -0.720320, -0.345340, -1.103660, -0.029810, 0.219990, 0.599220, 0.072210,
3.495250, -0.091030, 0.497170, -0.590380, 0.346060, 0.910140, -1.504280, 0.314980, 0.681390, 1.756330,
-0.378260, -0.700870, -1.176890, -3.592860, -0.672740, 0.447500, -2.201960, -1.675210, 0.237830, -1.103560,
0.801960, 0.001610, -0.515790, 1.451290, 2.203250, -0.769610, 0.931370, 0.240710, 0.233690, 0.361300,
0.341240, 0.949440, -1.699110, -0.110940, 0.922810, -0.645660, -1.823860, 0.775830, 0.407140, 0.546780,
0.310860, -0.344430, 0.085660, -0.515660, -0.337280, -0.047620, 0.340580, 0.400100, 0.495990, -0.020380,
0.586700, -2.172880, -0.074060, 2.065260, 0.317340, 0.652230, 1.609450, 0.862590, 0.163330, -0.012460,
0.903880, 1.055010, 1.153180, -0.331210, -0.018910, 0.565750, 2.774350, -1.987350, 0.188640, 1.394950,
0.013310, 0.170150, -0.174980, -0.477610, -0.703180, -0.041130, 1.860430, 0.344490, -0.326740, 0.163330,
0.315570, 0.149890, -3.082020, -1.004080, 0.650020, -0.918630, 0.602990, -1.023410, 1.042860, -0.785220,
-2.842740, 0.521140, 0.834480, 0.396440, -0.885700, 0.827030, 0.829110, -0.171090, 3.653630, 2.413900,
0.882560, -0.287140, -0.125920, 0.600110, 0.760750, 0.967310, 0.441880, 0.560240, -1.684870, 0.734610,
1.561750, 1.728290, 1.180110, 0.332450, -0.446850, 2.313580, 1.287540, -0.278020, -0.692990, 1.239380,
-1.511190, -0.056200, 6.200350, -1.308920, -1.419760, 0.644150, 0.638720, 0.130950, 2.553240, 0.309820,
-0.580490, -1.062220, 0.830070, 0.138910, 0.158000, -0.037420, -0.624730, -0.376860, -1.080040, 0.336890,
-0.294350, -0.547680, -0.257710, -0.130580, 0.051340, 2.619960, 0.773950, -1.162540, 2.022490, 1.363190,
1.704300, -1.498040, -0.759710, 0.431030, -0.847300, -0.889140, 0.381390, 1.270840, 0.412580, -0.134080,
1.151360, 1.629090, -0.729190, 0.947030, -0.049440, 0.224230, -0.872430, -0.162980, 1.932320, 0.656050,
0.620280, 0.493410, 0.365320, -0.929990, 1.765290, -0.049900, 0.901240, -0.073840, 0.034430, 0.269300,
-0.006920, 1.641770, 0.455850, -0.552400, -2.338130, 0.238610, -0.087560, 0.680530, -0.451010, -0.119010,
0.218880, -1.335060, -0.426470, -0.154720, 0.501980, 1.634140, -0.523380, 0.275950, 1.164610, -0.121190,
-0.890560, 0.583660, -0.940810, -0.111390, -0.748630, 1.062640, 0.603550, 1.032980, -0.038170, 0.479330,
-2.518580, -1.118540, -0.812100, -0.391010, 0.202390, 0.833290, -0.482090, 0.075980, 0.203060, 0.468490,
-1.483650, 0.904630, -2.962980, -0.154570, 1.809720, -4.476510, 0.146090, 0.233670, 1.619830, 0.161790,
0.575260, 0.173690, -0.613460, 1.039650, -3.810130, 0.434930, 0.784890, 0.210010, 0.243000, -0.675560,
-0.600890, 0.631820, -0.563890, 0.073570, -0.643630, -1.240520, -0.041250, -0.048020, 0.653970, -0.779290,
-0.568970, -1.210790, 0.078370, 1.228490, 0.612610, 0.012940, 0.919240, -0.854890, -0.060850,
0.388940, 1.576920, -0.516720, -0.401540, 0.255530, -0.072770, -0.878620, 0.489460, -0.421960, -0.039800,
-0.310520, 0.855910, -0.724140, 1.022130, 0.356880, 0.703730, -0.103360, 0.274140, 0.392970, 1.753680,
1.142670, 0.631650, -0.131330, 0.050930, -1.102590, 0.386880, 0.162630, 0.588210, -0.802790, -0.855020,
1.774310, -0.519360, -0.613810, 0.553910, -1.038390, 0.303290, 1.549080, -0.175190, 1.027030, -0.907980,
0.685620, 0.472850, 0.570860, -1.009240, 1.296820, -0.011340, -1.425020, 0.440220, -1.325130, 0.590700,
-0.275790, -1.144800, 1.805600, -0.812330, 0.628790, 1.071540, -0.129340, -0.474000, 0.712890, -0.831590,
-0.243100, -0.254740, 0.517670, -0.045210, 1.344400, 0.383910, -0.771740, -0.102900, -0.369940, -0.733310,
0.309720, 0.710230, 0.599740, -0.334560, -0.471130, -0.561420, -0.070920, -0.894040, 0.383920, 0.787900,
0.562920, 0.039130, 0.286180, -0.001960, -1.411950, 0.726940, 0.568370, 1.464720, 0.286250, 0.216840,
0.687380, -0.665110, -0.236720, -0.583800, 0.996030, -2.932060, 0.363880, 0.091550, 0.614390, -0.453490,
0.474260, -0.797440, 2.657730, -0.132290, 0.367560, 0.192630, -0.482620, 1.705330, -0.299070, 1.576170,
1.174180, 0.242370, 0.071110, 0.840800, 0.270300, -1.491780, -1.218470, -1.179300, -0.135930, -0.061580,
-1.376200, 1.770290, -0.153950, -1.298240, -5.972650, -0.514210, 1.982210, 1.094780, -2.048210, 1.464650,
3.037300, 0.667500, -3.451990, 0.534450, 0.569450, -1.137470, -0.251360, 3.030420, -0.492160, 0.861500,
1.651330, -0.530440, -1.937440, -0.704700, 0.747570, 0.823060, 0.693000, 1.229430, -0.307300, 0.150500,
0.042540, -0.616520, -2.423470, -0.237440, 1.927500, 0.676530, -1.040530, -0.817590, -0.528740, -0.231300,
1.008820, 0.050190, -1.637180, 0.143720, -0.098200, 0.998830, -0.642240, 0.048650, 1.628480, -0.215660,
1.249630, 0.496560, 0.106170, -1.275560, -0.515190, 0.544550, -0.634090, 1.417680, 0.394600, 1.170630,
-2.102340, 0.072420, 0.284770, 0.226840, 2.560820, -1.657430, 1.208630, 0.220050, -0.129150, -0.232790,
1.096350, -0.362460, -1.247140, -0.544780, 1.000480, -1.141660, 0.095800, -1.320970, -1.016030, 0.587560,
-0.012990, 0.329220, 1.925770, 0.595190, -0.855250, 0.770080, 0.694980, 1.863420, -0.517660, -1.832690,
0.365520, 0.658000, 1.092000, 0.472060, -1.480000, -0.215320, 1.077370, -1.119340, -0.614310, 0.865720,
-0.324120, 1.035870, 0.998320, 0.871710, 2.715860, 0.893160, -0.434850, -1.324500, 0.750080, 0.297420,
0.370240, 0.418460, 0.335300, -0.683520, 0.323010, 0.769580, 1.075770, -0.090600, -0.463310, 0.031020,
-0.183070, -0.482770, -0.935180, 1.673910, -0.268200, -0.104520, 0.776320, -1.965140, 2.171270, 0.010590,
0.503100, -0.335580, -0.142740, 5.131400, 0.400210, 0.106040, 0.438180, 0.520230, 1.043360, 0.046040,
1.172490, 1.651180, 2.576520, 3.010740, 0.506830, 0.811650, 0.434840, 1.910360, 1.626020, 0.228570,
0.322990, 1.222460, 0.818440, 0.482160, -0.084660, 0.676130, 1.061930, -0.137610, 1.574360, 0.372100,
0.850930, 0.391850, 0.664780, 0.378340, -0.109080, -0.355970, -0.170950, 0.297650, -0.283530, 0.137080,
0.075590, 0.595340, 0.515600, 0.942050, 0.362050, 0.828920, -0.071680, -0.462740, -0.843170,
-1.313890, -0.094940, -0.486420, -0.541440, -0.883880, -0.581260, -0.190200, 1.369260, -0.167240, 0.865480,
-1.166890, 0.044940, 1.161390, 0.426250, 0.039680, 0.296220, 0.451290, 0.188250, 0.575200, 0.716110,
-0.297360, 0.823900, 0.267770, -0.321240, -1.555220, 0.393540, 0.010420, 0.861490, -0.484760, -0.932030,
0.959850, -0.272370, 0.045160, -0.163900, -0.009910, -0.608200, -0.790830, -0.149370, 0.300910, -0.381020,
-2.855560, 0.197090, -0.801340, 0.868630, -0.916750, 0.185130, 0.094420, -0.302680, -0.347840, -0.281030,
0.088510, -1.244970, 0.112550, -0.354290, -1.240530, -1.514310, 0.316650, -0.742640, 1.639330, -2.926700,
-2.380880, 0.535370, -0.107260, 0.180470, -1.705310, 0.032940, 1.343850, -1.246460, 0.056630, 0.148010,
-0.027150, 0.149880, -0.482120, -0.310990, 0.122950, 0.594090, -1.333350, 1.191350, -1.278840, 0.314350,
-0.459580, -0.293740, 0.767020, -0.299240, 0.238030, -0.757440, 0.076370, 0.224020, -0.790290, -0.568700,
1.925140, 1.318680, -0.640980, -0.262650, -0.981330, 0.863400, 0.088160, -0.278640, 1.847540, -0.108720,
-0.990220, 0.311060, -0.218340, 2.051760, -0.122020, -0.842630, -0.033280, -2.253750, -1.071660, 0.230420,
1.270810, -0.932580, -0.924290, -0.106310, 0.791950, -0.060420, -0.021570, -1.967930, 1.595760, -2.429270,
0.178480, -0.256740, -0.829600, -0.016680, -0.373080, -1.149390, -0.409480, -0.761730, 2.005990, -1.089780,
-0.698690, 0.432540, -1.083580, -0.724630, -0.768880, -0.275180, 0.344010, 0.022140, -1.094110, -6.297500,
0.005430, -0.948190, 1.713020, 0.604370, -0.024190, -0.305380, 0.819050, -0.247710, -0.703220, 1.267270,
-0.886690, -0.164500, -0.070250, 1.257470, 0.105200, 0.572410, 1.621160, 0.299800, -0.907860, 1.146890,
-3.737710, -0.133590, 0.936420, 0.760030, -0.740900, 1.887010, 1.442220, -0.679020, 0.761870, -0.104840,
-0.770120, -0.055100, 1.621280, -1.141620, 0.874850, -0.257730, -0.758160, -0.153070, 1.598670, -1.554970,
-1.046810, 2.116650, -2.859660, -1.851310, -0.977320, -0.790380, -1.769660, -0.579480, 0.907540, 0.126750,
0.132290, -0.959870, -2.124970, -1.553770, 0.073710, 0.918840, -0.084190, -2.045550, -0.226390, 0.257720,
-0.670820, -1.327400, 0.763710, -0.044300, 0.388350, 0.196790, -1.569840, -3.001850, 0.254300, -0.173340,
-1.307810, -0.874940, 0.329290, 0.949330, -1.481190, -1.483770, 0.242930, -0.099700, -0.447010, 0.878640,
1.319790, 0.690270, 0.659900, 0.347190, -0.115810, -0.791760, -0.119720, 0.085730, -1.503480, 0.277040,
0.240390, 0.341990, -0.458840, -0.843210, 0.451570, 0.348380, 0.442770, 0.551570, 0.111880, 0.348130,
-0.735430, -0.365210, 0.426820, 0.331810, 0.728750, -0.699150, 1.137780, -0.498660, 0.554030, -0.374000,
1.137630, -0.097980, 0.410840, 1.526200, 1.242540, 0.306760, -0.479570, 0.568660, -1.080160, -0.975800,
-1.485250, -0.500260, -1.206350, -8.147240, 1.068700, -2.000250, -0.924080, -0.364330, -2.820740, -0.292760,
-1.101740, -1.060820, 0.055260, -2.372020, -2.204170, 0.156740, -1.590850, -1.160220, -1.175380, -0.434730,
-2.524410, -0.554820, -2.720480, 0.059280, 0.921380, -5.444700, -0.776900, -1.576370, -1.252560, -1.086690,
-1.740410, -1.864170, -5.189230, -1.808310, 1.378080, -0.882270, -1.248360, -1.222000, 0.341720,
-1.613350, -0.370730, -3.363720, 0.082740, -3.381440, 4.471890, -1.016380, 0.993880, -0.276690, -37.316101,
-6.009260, 2.116410, 1.120840, 0.457790, -1.140900, -8.045340, -0.714520, -0.166130, -6.246580, -0.384190,
-1.861780, -1.035610, 0.796530, 1.540510, 2.289230, -0.744040, -5.014020, 0.132180, -0.174440, 3.045770,
-2.719010, 0.378420, 2.347150, -0.708940, 2.391650, -0.357730, 0.332070, -0.678970, 1.477310, -0.240550,
0.729640, -0.378040, -0.036150, -0.650990, -0.933400, -4.164220, 1.056000, 0.880850, 0.226650, 0.237130,
-0.096960, 1.125950, -0.608750, -0.609630, 0.875690, -0.335320, -6.206260, 0.042410, 0.620960, 0.643580,

0.904430, -0.318680, -0.493800, -0.063140, 0.726850, -3.916230, -0.659990, -0.546560, -0.039470, -1.022880,
-1.113450, -1.411320, 1.058060, -0.957190, 0.181040, 0.162940, 0.411410, 0.175710, -3.938620, -3.987140,
-0.992380, -0.978400, -1.251550, -1.620130, -1.667620, 0.923290, 0.479950, 0.457170, -0.955580, 1.423870,
0.462860, -0.006890, 0.067670, -0.584220, -0.593620, -0.968180, 0.753880, 0.923600, 2.058840, 0.392470,
0.567980, 0.643620, 0.027390, 0.270240, 0.465490, 0.167190, -0.498800, -0.737520, 0.607960, 2.080260,
-0.501820, -0.454000, -0.612050, 0.787790, -0.543430, 0.272260, 0.068740, 0.069720, -0.246170, -0.320730,

1.076850, -1.210200, -1.082200, -0.307900, 3.096560, -2.584850, -0.299950, 0.381950, -0.422600, -0.379480,
-0.709300, -0.598130, 0.751310, -0.897850, 0.014320, -0.220660, 0.278890, 0.513780, -1.643130, -628.506470,
-0.729840, -0.599530, -0.434670, -0.346350, -1.589610, -0.075010, -0.159380, -1.252650, -1.477550, 0.865020,
0.676910, -0.919860, 1.674140, 0.175190, 0.527440, -0.300970, -0.060130, 0.478370, -0.169920, -0.448280,
0.102980, -0.651100, 0.049080, 0.570530, 0.108200, -6.531350, 1.289300, 0.061090, 0.126170, -6.950810,
0.446000, -1.064300, -1.290700, 0.065290, 0.389700, 3.604530, 0.471220, 0.362000, -1.036080, 0.840580,

2.059580, 0.690980, -0.521310, 0.601570, 2.824420, 1.111940, 1.226860, -2.032040, 0.651040, -0.800370,
-0.976930, 84.433723, 1.621310, -0.598450, 1.587080, -0.910820, -1.764250, -0.396800, -0.384190, -0.416500,
0.924560, -0.051650, 0.969370, 0.139900, 0.520620, -0.859850, 0.751790, 2.124340, -0.491400, 0.520810,
2.764140, -1.179210, 2.580470, -0.629700, 0.094870, -4.650130, 0.747240, 26.513790, 9.661030, 1.796720,
0.252510, -0.522710, -0.912120, 0.294100, -0.540720, 10.644310, 6.835320, 0.649170, 0.785780, -7.703220,
0.832160, -0.070750, -0.920140, 0.676250, 0.716790, 23.555960, -3.121950, 0.468390, -0.469620, -0.525100,

0.855750, -0.156690, 0.432600, -0.225000, -0.184840, -0.021370, 0.500260, -0.551170, -0.868260, -0.825080,
-0.385170, 0.557890, -0.632890, -0.675640, -0.924230, -0.688280, -0.054030, -0.386840, 0.829560, 0.691830,
0.103250, -0.600580, -1.056040, 1.023340, 0.157480, 0.061300, 0.043450, -0.781020, 0.725120, 0.513610,
-0.502320, -0.860560, 1.550300, 0.132600, 0.371780, -0.567850, -0.387490, -1.776370, -0.435280, -0.065970,
-0.219880, 0.246520, -0.690700, -0.749550, 0.640290, -3.439860, -0.075360, 0.232130, 0.509180, 2.388280,
-0.213100, 0.014590, -0.752000, -0.455500, -0.334420, -0.888960, 0.636750, 0.144370, 0.205460, 1.126610,

-2.724100, 0.620540, 1.209490, 1.184730, -3.026680, -11.069240, -0.384330, 0.890100, -0.687970, 2.141340,
-1.066490, 6.229370, -0.701420, -26.221889, 0.730880, -0.984780, -3.607470, -1.010290, -62.822102, -1.053140,
-0.620740, -0.944500, -0.396910, 3.855190, -41.575142, 0.360280, 0.049900, -0.349080, -1.231160, -1.714680,
-8.695450, 0.898170, -1.154330, 0.516450, -2.273670, -0.442010, -0.036720, -1.063600, 1.832420, -0.676950,
0.432040, 0.456260, 0.513910, -1.010930, 0.643310, 2.315040, -3.205610, 0.055260, 0.123530, -41.163811,
0.319550, 0.504770, 0.357180, 0.539930, -0.214260, 0.128260, 1.989930, 6.303500, -0.227270, 0.638940,

-0.865270, 0.119940, -0.081630, 0.336130, 0.056500, 1.022720, -0.303910, 0.046990, -0.841730, -0.169530,
1.858960, 1.653730, -0.066900, 0.433170, 0.305450, -0.791150, 0.889060, -0.106710, 0.674480, 0.354130,
0.073350, 1.309470, 1.099600, -0.674660, -0.471520, 0.583230, 0.876540, 0.911930, 0.472210, -0.338840,
-0.204380, -0.229180, -1.120230, 0.204340, -2.007060, 0.511270, -0.510330, 0.744920, -0.935470, 0.888040,
-0.378040, 0.382790, -0.341980, -0.152060, 0.185300, 1.396140, 0.115840, -0.672430, -0.847120, -7.191530,
-0.322630, -0.181310, 0.728120, -0.085520, 0.294160, 0.333340, -0.735550, 0.736960, 0.046550, 0.058660,

-0.494290, 0.342150, 0.094280, -1.112930, 0.326020, 0.288680, 0.836320, -0.026060, 0.697200, 0.222020,
0.581410, -0.936070, 0.574080, -0.208280, 0.621900, 0.263220, 0.220180, -0.111330, 0.632410, 0.226100,
0.492740, -0.949120, -0.653880, -1.413580, -0.871910, 0.916190, -2.080750, -0.093530, -0.081540, 0.952440,
-2.878070, -0.999990, 1.251900, -1.037810, 0.160950, 0.196610, -0.268650, -0.588920, 0.039450, 0.744260,
0.763310, 0.591850, -0.297240, -0.955950, -0.758960, 0.878590, 0.428620, -0.955310, 0.839650, -302.051086,
-0.264790, 0.545300, -0.511120, -0.495640, -0.507060, -0.360580, 2.136720, 1.327910, -0.679440, -0.563730,

-2.686670, 0.404260, -1.086290, 2.923100, -1.939040, -1.141620, -0.627480, 0.368110, -0.551800, -0.337320,
0.467200, 0.922150, 1.332510, -1.187370, 0.264960, 0.028260, -0.695780, 0.332110, -0.581920, -2.113340,
-0.882570, 0.316250, 0.002510, -0.465750, 0.023650, 0.186400, 0.426440, -0.190870, -0.093510, 2.501430,
-3.779950, -0.380730, 0.867500, -0.290490, -0.035830, -0.252510, 0.463220, -0.029560, 0.837150, 0.677940,
-0.201560, 0.600980, 0.756770, 0.327040, -0.485370, -2.545800, 0.744070, -0.234370, -1.111620, 2.811540,
0.586500, -0.950610, -0.439110, -0.530030, -1.149570, -0.353320, -0.132070, 0.197770, 0.660080, -0.304790,

0.930790, -0.885330, -0.779630, 0.620940, 0.441040, -2.614800, -0.278870, 0.624860, 0.275060, -1.396670,
-1.216700, -0.906310, 0.001090, -1.016160, 0.976880, 0.816560, -3.323130, 1.103850, -0.845170, -1.021200,
-0.919300, -0.230280, -1.134380, -0.544790, 0.142130, 0.175730, 1.084200, -0.637890, 0.034510, 0.622960,
-0.543930, -0.147880, -1.297640, 0.268900, 0.518880, 0.120780, -0.817570, -1.166480, 0.904040, -0.306360,
0.863550, 0.806400, 1.149330, 0.472580, 0.180770, -0.222840, 0.586050, 0.793580, 0.757130, 8.295640,
0.067230, -0.471860, -0.515170, -0.405380, -0.431290, 0.761440, -0.140330, -1.025600, -0.649480, -0.573900,

0.043050, -0.212460, -0.099680, 0.350290, 0.079850, 0.940860, -0.644980, -0.389800, -0.822860, -0.048680,
0.534450, 0.222440, -0.351500, -0.059260, -0.082300, 0.556870, 0.640390, 0.294680, -0.220830, -0.582800,
0.160330, 0.224170, 0.469950, -0.422180, -0.114690, 0.368590, 0.287270, 0.125740, 0.021850, -0.204920,
0.217290, -0.504870, 0.307010, -0.041010, -0.256020, 0.624780, -0.599550, 0.348030, -0.147610, -0.104320,
1.060670, 0.738060, 0.098230, 0.030210, 0.299810, 0.937010, 0.519550, -0.229940, 0.902170, -0.695130,
0.619350, -0.611640, 0.234270, -0.778220, 0.879000, 1.385840, 0.155470, 0.293440, 1.059220, -0.384940,

1.532630, -0.343730, -0.713660, 0.319760, 0.584500, -4.137960, 0.233120, 0.487190, 0.739520, -0.067620,
-1.496350, -1.274830, -0.371590, -1.491060, -0.246550, 0.690070, 0.043090, 0.187730, -2.680950, -7.383970,
-1.819460, -0.198480, -2.133890, -1.004740, -1.174870, 0.585820, 0.576190, -0.350310, -1.016440, 0.728250,
-3.087380, -1.011910, 1.169610, -0.245540, 0.517400, 0.495670, -0.270440, 0.683440, 0.914730, 0.616390,
0.913300, -0.739320, -0.981790, 0.305670, 0.010750, -0.230410, -0.197570, 0.265700, 0.416310, 2.540470,
-0.027230, 0.426940, -0.606410, -0.598660, -0.313580, -1.436940, 0.667420, -0.325050, -0.033710, -0.327430,

-0.415550, 0.355150, 0.468280, -0.390100, -0.061260, 1.164950, -0.975900, -0.868070, -0.266710, 1.014790,
1.092650, 0.419400, -1.316760, 0.487790, -0.190860, 0.499430, 2.101080, 0.632270, -0.804760, -0.724830,
-0.224210, -0.647200, 1.450480, -0.017160, 0.828060, 0.490240, 0.772700, -0.825520, 0.896040, 0.061040,
0.124520, 0.424280, 1.447290, -0.526390, 1.046810, 0.689730, 0.661770, 0.086610, -0.160160, 0.277640,
-0.667280, 0.816660, 0.782330, 0.214200, -0.107800, 0.284260, 0.276050, -0.442070, -0.965080, -2.091950,
0.234130, -0.288140, 0.215730, 0.116390, -0.377850, -2.618730, -0.327360, 0.478000, -0.618780, 0.841160,

0.267860, -0.109540, 0.095380, 0.254640, -0.029080, -1.035680, -0.680690, -0.772510, -0.128880, -0.166360,
-0.093060, 0.267830, 0.103150, 0.052270, -0.046850, -0.348660, 0.588300, 0.628730, -0.118670, -0.520620,
0.329440, -0.060780, -0.512120, 0.132320, 0.217060, -0.074250, 0.424190, -0.839110, 0.441580, 0.139570,
-0.429770, -0.303870, -0.006230, 0.911460, 0.033100, 0.437000, 0.226590, -0.344030, -0.078700, 0.042160,
-0.845180, 1.119390, -0.325950, 0.650760, 0.863520, 0.106040, 0.132100, -0.586110, 0.858410, 5.995910,
0.841140, -0.876490, 0.194840, -0.682890, 0.463490, -0.850740, 2.918700, 0.429080, 0.558160, 0.366370,

-0.546790, 0.556120, 0.000390, -0.904480, -0.407210, 0.922920, 0.026920, -0.726370, -1.107620, 0.498620,
0.912490, 1.253190, 0.058900, 0.599060, -1.369920, -1.454560, 1.854470, -1.449480, 0.525000, 0.137640,
-0.419660, -0.541710, -0.061260, 0.002440, -0.526450, 0.010920, -0.172530, -0.717290, -0.153910, -0.716960,
2.400590, 0.737240, -0.729410, 0.384490, 0.454710, 0.278700, 0.593290, 0.205460, -1.845020, 0.427960,
-0.084560, -0.568240, 0.076850, -0.313150, 0.028250, -2.517720, -0.310780, -0.015200, 0.630370, -31.565331,
0.331580, 0.223910, -0.515400, 0.014430, -0.340620, -7.870040, 0.772040, 0.514270, 0.507090, 0.056960,

0.426510, -1.471290, -2.461640, 0.045320, -0.006690, -3.931840, 0.273450, 0.056990, -0.044680, 2.428560,
-3.474620, 0.324060, 0.084390, 0.054410, 0.166420, -1.349460, 4.017190, 0.927410, -7.176570, -1.355660,
-3.300690, -1.018930, 0.154130, -0.050310, 1.613210, -0.094280, -0.896080, -0.204410, -1.083800, 0.138200,
-0.296220, 0.024290, -6.207960, -1.008460, 2.628100, -10.499850, 0.678420, -0.898280, -0.594150, 0.459030,
0.643090, 0.333870, -0.915770, -0.695730, -0.008120, 0.249390, 0.766630, 0.244900, -0.552540, 4.480550,
0.922530, 0.547750, -0.431190, -0.540390, -0.868260, -0.067810, -21.408131, 2.255050, -0.230480, -0.236630,

0.251160, 0.575500, 0.464170, 0.516600, 0.613610, -0.554080, 0.083350, -1.453880, 0.775590, -0.054180,
-0.022130, 0.542190, 0.221050, 0.177270, -0.386130, -0.479870, -1.041770, -0.316680, 0.449850, 0.462440,
0.417380, 0.805570, -0.571160, -0.264670, -0.745200, -0.791190, 0.696510, -0.933610, 0.102660, -1.107100,
-0.269800, 0.072040, 0.840200, 0.277380, -0.802670, -1.270910, -0.721450, 0.922950, 1.294520, 0.593520,
-0.077380, 0.222070, 0.651280, -0.903370, 1.292950, 0.956910, -0.313590, 0.722550, 0.600400, -1.941140,
-0.173700, 0.820450, -0.344890, -0.845780, -0.676470, 0.462840, 0.551200, -0.395150, 0.037210, -0.797570,

0.294000, -0.041440, -0.298950, -0.088910, 0.640000, -0.768260, 0.559280, -0.278880, 0.003130, -0.719440,
-0.823460, -0.572720, -0.005630, -0.369390, 0.565790, -0.027400, -1.234940, 0.156140, -0.485230, -0.256450,
-0.105800, -0.578780, -0.255760, -0.379680, 0.108720, 0.523490, -0.299570, -0.636030, -0.031220, 0.007530,
0.586800, 0.545380, 0.703780, 0.437100, 0.236350, -0.509300, -0.009440, 0.822350, -0.641360, 0.821690,
-0.500650, -0.708380, -0.001970, -0.794020, -0.379190, 0.196750, -0.305460, 0.382480, -0.457980, 16.141720,
-0.557340, 1.009170, 0.340620, 1.033710, 0.382550, 0.093950, 1.064500, -1.026910, 0.949050, 0.273460,

0.062450, 0.123280, 2.596220, -0.839340, -0.637440, 19.615620, 0.827690, -0.325460, 0.744290, 2.441890,
1.135740, -0.034910, 0.556560, 1.291930, 0.339720, -0.873970, -1.798690, -0.763430, -3.802760, 0.246970,
0.132510, -0.162910, 5.669040, -1.665020, 0.560250, 0.199340, -0.553970, -0.566070, 1.388170, 6.877220,
-1.408410, 0.054420, -0.938090, 0.313840, 0.796440, -5.282560, 1.202290, -0.579640, -1.090250, 0.410030,
0.723970, 0.143670, -2.878780, 1.271060, 0.266240, -0.634680, 0.499420, 0.160380, -0.280740, -3.869580,
0.764320, 0.445020, 0.388060, -0.285070, 1.230200, 0.672690, 5.945890, 11.364570, 1.042100, 0.796230,

-1.960070, -3.929260, -6.174240, 6.741040, -12.433860, -2.974870, -2.581490, 0.925260, 0.465350, -1.543220,
1.465410, 3.296210, -2.189300, -3.731610, 0.578900, -1.227910, -1.210850, 3.729800, 0.466280, -2.994380,
0.296080, -5.063800, -2.027920, -0.940700, -1.688070, 1.565350, 4.711310, -4.795570, -3.962160, 1.893650,
-0.785160, 1.868460, -0.101670, 0.867340, -1.008320, -1.799670, -2.928250, -1.205520, 5.200460, 0.842220,
-0.312330, 1.204690, -1.332780, 0.694680, -1.208520, -1.099210, -2.847100, -0.449890, -0.463200, -0.708690,
0.798310, 0.509420, -1.321620, 1.859790, -2.218530, 3.530950, -2.825250, 0.173680, -0.601870, -2.069860,

2.341600, -0.463210, -0.235580, 0.579510, -0.050500, -0.708720, 0.196310, 0.024270, -0.361990, -0.692350,
0.151250, -0.198920, 0.911510, 0.167730, -0.330170, 0.250400, -0.911430, 0.732390, 0.316200, -0.276920,
0.644960, 0.506860, -0.515090, 0.548830, 0.231860, -0.375940, 0.083900, 1.022750, -0.242470, -0.375540,
1.539690, 0.461040, 0.305520, 0.003710, 0.700700, -0.539650, -0.381280, -0.556030, 0.595720, -0.138900,
0.392330, -0.104790, 0.798900, 0.665790, -0.577620, -1.298150, 0.740770, 0.247070, 0.285510, 17.004660,
0.021890, -0.015410, 0.638040, 0.079570, 0.088110, 2.318450, 3.997110, -0.139540, -0.398880, 0.223930,

1.294770, 0.303510, -0.132680, -0.326130, 0.139450, -0.700380, 0.247430, 0.927380, 0.974490, 0.401180,
0.993900, -0.569350, -0.557740, 0.040600, -0.925560, -0.369370, 0.915640, 0.203700, 0.118100, 0.739520,
0.948860, 1.265140, -0.861390, 1.091450, 0.674370, -0.186240, 1.139990, 0.996340, 0.738040, -1.371530,
-0.613620, 0.510790, 0.726910, 0.088390, 4.043900, 0.516300, -0.559030, -0.263790, -1.454010, 0.510640,
-0.996310, 0.451350, 0.612790, 0.665130, 1.054750, 0.279320, -0.219420, 0.078810, 0.296360, -1.415960,
0.126730, -0.437370, -0.182680, -0.569180, 0.505610, -1.082810, -1.632290, 0.536320, -0.361370, 0.230980,

-0.191850, 0.030860, 0.278540, 0.100490, -0.568860, 0.864310, -0.302030, -0.719150, -0.137750, 0.730110,
0.698850, 0.377740, -0.293890, 0.131770, -0.462170, 0.374580, 1.150280, 0.024380, 0.199770, 0.262710,
0.634900, 0.184720, 0.509030, 0.312910, 0.184270, -0.244080, 0.101020, 0.334700, 0.036550, -0.367500,
0.308830, -0.674620, 0.956720, 0.667650, -0.593750, 0.156060, 0.736740, -0.218890, -0.463310, -0.206170,
-0.048730, -0.116910, 0.212680, 0.877500, 0.186670, 0.010520, 0.366870, 0.263970, -0.084860, 0.054670,
-0.111590, 0.708970, -1.022550, -0.791370, -0.837270, 0.814520, 0.622250, 0.628550, -0.903750, 0.408970,

-0.218660, 0.290520, -0.001820, 0.207610, 0.653400, 0.242220, -0.344170, 0.075290, 0.256280, 0.172150,
0.460490, 0.416560, -0.021750, -0.064530, 0.450000, -0.128580, -0.171950, 0.469940, -0.226740, -0.201940,
-0.216460, 0.318470, 0.733800, -0.618750, -0.005710, 0.152870, 0.342900, -0.107700, 0.139330, 0.001710,
-0.323230, -0.270600, 0.101540, -0.033710, 0.181400, 0.363770, -0.703310, -0.152180, 0.120560, -0.160930,
0.383750, 0.466940, -0.113400, -0.650670, -0.213580, 0.603430, 0.415680, -0.945010, 0.575660, 0.464460,
0.917680, -0.621960, 0.380560, 0.666490, 0.792860, -0.123320, -0.073480, -0.311130, -0.192520, -0.830600,

-0.019100, 0.367630, 1.121230, -0.481740, -0.591240, 1.456060, -0.009510, -0.378470, 0.361040, 0.381510,
0.791750, 0.094340, -0.166700, 1.420830, -0.401610, -0.627610, -1.282380, 0.442300, 3.032380, 1.846290,
1.334500, 1.872780, 0.074660, 1.309340, 2.616050, -0.260440, 0.356150, -0.337780, 2.359380, -1.542510,
1.873970, 0.628520, -0.304350, -0.567200, 0.138200, 0.556090, 1.087000, -0.568160, -1.505600, 1.039380,
-0.435360, -0.170520, 0.616190, -0.351450, -0.224130, 1.213710, 0.278320, -0.089580, -0.592920, -3.257060,
0.469100, -0.233100, -0.547910, 0.803630, -0.507110, 0.779310, 0.558810, 0.321450, 0.416760, 0.767620,

-0.015590, -0.803600, -0.131000, 0.353440, 0.360750, 0.613970, -0.256120, -0.657880, -0.968820, 0.043460,
0.575970, -0.070390, -0.104670, 0.743220, -0.181440, 0.321550, 1.492250, 0.735090, 0.475320, -0.634730,
-0.566950, 0.769070, 0.393700, -0.286740, 0.444110, 1.110140, 0.193150, 0.827640, 0.777080, -0.214300,
-1.308320, 0.711450, -0.953700, 0.667350, -0.749410, 0.304570, -0.534580, -0.079340, 0.738350, -0.589070,
0.758310, -0.422150, -2.666280, -0.500610, -2.992380, -0.302670, -0.851120, 0.389810, -0.984250, 0.572790,
-0.248520, -0.017330, 0.009180, -0.715180, -0.821240, -0.810900, 2.562140, 0.347350, -0.537280, -0.392070,

-0.146370, -0.504740, 0.709860, 0.093910, -0.497480, 1.564150, -1.701110, -0.141320, -1.117560, 0.041980,
-0.108840, -0.282970, 0.352500, 0.554500, -0.957520, -0.039810, 0.096120, 0.245790, 0.123770, 0.022170,
0.473340, -0.647110, 0.200800, 0.767830, 0.207150, 0.411420, -0.757910, -0.816120, 0.183360, -1.000020,
-6.429690, 0.089720, -0.983330, 0.035450, 1.610870, 1.035980, -0.473220, 0.663780, -5.267720, -0.311210,
-1.161010, -0.376660, -0.106580, 0.375530, -0.311720, -1.172450, 0.861130, 0.191400, -0.348940, 4.682240,
0.632230, -0.567560, 0.821150, 0.034370, -0.771670, 2.709400, 0.037650, 0.104680, -0.442400, -0.243940,

-0.332310, -0.092190, -0.324820, -0.473320, 0.004710, -0.343450, 0.380030, 0.514490, -0.640510, -0.586690,
0.641630, -0.014290, 0.320130, 0.248130, -0.345560, 0.289160, -1.591940, -0.566350, 0.059420, -1.358110,
0.271800, 0.634000, 0.988120, 0.290120, 0.177940, 0.003430, -0.112260, 1.251240, -1.385050, 0.746670,
0.039600, -6.237440, -40.253231, 0.094950, -0.594780, 1.914830, 0.427010, -3.270030, -1.034030, -1.702260,
0.614750, -0.657140, -0.044480, -0.105030, -0.627210, 2.645540, -0.225220, -0.248670, -0.384070, -392.343353,
0.136060, -0.974410, -0.149730, 0.045890, 0.554920, 0.109720, 2.778640, 1.354580, -0.948620, 0.697140,

0.646890, 0.475360, -0.355120, -0.527690, 0.153560, -0.617070, 0.592310, 3.097320, 0.797790, 0.715790,
-0.996010, 0.370580, 1.547760, -0.741140, 1.346590, -2.774050, -2.548560, 3.433460, -0.657900, -0.431240,
-0.993930, -0.073800, -1.103750, -0.109650, 0.754740, 0.331260, -1.608050, 0.850690, 0.751670, -0.970610,
1.594810, 3.412710, 10.250450, 0.679870, 0.127120, -3.585970, 0.418500, 6.352300, -4.816610, 1.530600,
0.119510, 0.296580, 1.574150, 0.519500, -7.054910, 1.689610, 9.570660, 0.924460, 0.447990, -5.673850,
1.216570, 0.680540, 0.283580, 0.546070, 1.222170, 0.428800, 0.581650, 206.295532, 0.080820, -0.319130,

-0.572390, 0.797150, 0.596150, -0.305080, -0.837920, 0.411340, -0.761290, 0.187800, -0.532600, 1.981960,
-0.091580, 0.827980, -0.377540, 0.580190, -1.075820, -0.856140, 2.864150, -0.786560, 0.379960, -0.037810,
0.803830, -0.282200, 0.155400, 0.570500, 0.835720, -0.995050, -0.405250, -0.356690, 0.301890, 0.176130,
-0.607980, 0.265950, -1.362310, -0.497440, 0.897830, -0.108390, 0.361480, -0.698770, 0.122030, 0.398290,
0.225890, 0.345740, -0.993490, 0.133140, 0.506030, -0.534860, -0.137450, 0.412730, 0.562000, 0.103580,
0.323160, -0.362330, 0.457080, -0.705400, 0.063930, 0.036520, 0.276890, 1.981710, 0.489560, 0.052110,

0.363430, -1.663570, 1.159050, -0.487530, 4.715330, -0.039280, -0.688340, -0.749410, -2.917220, 0.431990,
0.295610, -0.284590, 1.255970, 0.612670, 1.015970, -0.312390, 1.222630, 0.892210, 0.687650, -6.405460,
0.016540, 0.635980, 0.219350, -0.653600, 0.573630, -3.707600, 31.669041, 0.721040, 0.668400, 1.771910,

0.770270, -0.893870, 1.001850, -0.030880, 9.295730, 0.286550, -0.641720, -0.658010, -2.621010, 0.891960,
0.887170, -0.558300, 1.056960, 0.448460, 3.132100, -0.002040, 1.045970, -0.706790, 0.146870, -6.327520,
-0.093270, 0.524040, 0.640780, -0.870560, 1.021070, -2.905350, 23.329849, 0.630430, 0.996780, 0.961620,

0.426940, -0.618840, 0.623810, -0.116270, 11.118430, 0.434620, -0.380900, -0.749030, -2.426800, 0.093740,
-0.450510, -0.701190, 1.039600, 1.010910, 1.878860, -1.126750, 0.778370, 0.461420, -0.416100, -5.691170,
1.113600, 0.608540, 0.327740, 0.068930, 0.780130, -2.370460, 10.811840, 0.509310, 0.795270, 1.208030,

0.738730, -0.361800, 0.679820, -0.222190, 12.515960, 0.573620, -0.346840, -0.827720, -2.298510, -0.492080,
0.556640, -0.295660, 0.893770, -0.353310, 1.736340, -0.692190, 0.814680, 0.595810, 0.232970, -6.061020,
0.272930, -0.269290, 0.675280, 0.796780, 1.118210, -1.638710, 12.784420, 0.595270, 0.017240, 1.005790,

0.896660, -0.660130, 0.318790, -0.504920, 7.952820, 0.636590, -0.314460, -0.807730, -2.241230, -0.948330,
0.667890, -0.248670, 0.823760, 1.015580, 1.025000, -0.797060, 0.946440, -0.381970, -0.790320, -6.315100,
0.778380, 0.931960, 0.116110, -0.109380, 0.742700, -2.621360, 2.293390, 0.420970, 0.524090, 0.626760,

0.953910, -0.446130, -0.138640, 1.017950, 6.459180, 0.698410, -0.567170, -1.052320, -2.434900, -0.730170,
0.327660, -0.706580, 0.686680, 0.256970, 1.407580, -0.696520, 0.954520, -1.016470, 0.854680, -6.918420,
0.030480, 0.451680, 0.413190, 0.559580, 0.428060, -1.743190, 0.216530, 0.331580, -0.717080, 0.182400,

0.944780, -0.642050, -0.134340, -0.023690, 3.540560, 0.704100, -0.091940, -0.922390, -2.423300, -0.699580,
-0.221590, -0.472190, 0.948150, 1.032970, 1.645440, -0.680230, 0.940510, -0.189800, 1.259250, -7.360260,
0.509610, 0.137030, 0.194930, -0.300840, 0.318490, -1.434610, 0.986470, 0.440640, -0.235800, 0.347350,

0.816400, -0.548220, -0.313440, 0.343860, 2.808730, 0.695820, -0.148130, -1.040740, -2.281300, -1.105880,
-0.153260, -0.548950, 1.101640, 0.970240, 0.926880, -0.651130, 0.950270, -0.386910, 0.718340, -8.067870,
-0.513090, 0.937330, -0.311590, -0.758920, 0.225810, -1.171900, 1.041720, 0.436830, 0.844800, 0.284320,

1.107580, -0.408820, -0.298890, -0.020200, 2.269590, 0.770930, -0.218560, -0.935580, -2.199240, -0.713470,
0.633940, -0.453660, 0.882050, -0.681370, 1.474210, -0.698520, 0.832280, -0.294070, 0.055800, -8.398850,
0.402680, 0.646780, 0.148970, 0.686250, 0.569140, -1.223140, 0.736490, 0.606150, 0.194790, 0.588420,

1.053100, -0.615560, -0.459260, 0.442850, 1.271010, 0.701920, 0.408140, -0.695520, -2.424770, -0.625490,
-0.791130, -0.049540, 1.015830, 0.431850, 1.221090, -0.818370, 0.777320, 0.451770, -0.183950, -8.511760,
0.413200, -0.788670, 0.621990, -0.547110, 0.223650, -1.146120, 1.210550, 0.654280, 0.711260, 0.789770,

1.074710, -0.477490, -0.589410, 0.735080, 0.687210, 0.823190, 0.409450, -0.729530, -2.241840, -0.555780,
1.132860, -0.225850, 0.933130, 0.218220, 1.157310, -0.739240, 0.702490, 0.273050, -0.724410, -9.862580,
-0.249720, -0.213520, 0.161250, -0.739880, 0.368610, -1.291710, 1.368220, 0.701390, 0.043240, 0.884710,

0.962220, -0.290070, -0.707620, 0.452190, 0.476640, 0.901110, 0.240860, -0.764160, -1.906850, -0.867850,
-0.941370, -0.269070, 0.860120, -0.258930, 1.229410, -0.919480, 0.502830, 0.530130, -0.295370, -10.862950,
-0.124740, 0.606010, 0.548870, 0.466620, 0.466670, -0.809010, 1.713480, 0.610990, -0.081650, 0.629480,

1.259630, -0.511360, -1.005040, -0.794020, 0.488390, 0.868360, 0.303680, -0.721060, -2.153030, -0.206650,
0.296090, -0.459100, 0.824920, -0.772720, 1.352420, -0.575850, 0.540240, -0.492090, 0.703070, -11.158200,
0.545660, -0.079790, 0.229730, 0.378850, -0.203960, -0.830600, 0.979100, 0.823810, -0.027310, 0.800820,

1.113520, -0.427240, -1.093680, -0.203930, 0.728400, 0.892120, 0.574890, -0.787170, -1.855590, -0.773780,
0.324690, -0.282020, 0.842780, -0.088170, 0.981600, -0.849890, 0.255370, 0.259100, -0.377190, -12.524400,
0.500550, 0.843040, -0.110870, 0.366490, -0.095660, -0.587380, 1.441550, 0.800480, -0.950850, 0.867880,

1.213440, -0.173490, -1.106110, -0.190080, 0.360420, 0.911380, 0.488570, -0.576320, -1.859320, -0.217310,
0.270110, -0.501400, 0.589410, -0.959070, 1.092720, -0.607700, 0.201610, -0.170840, 0.465610, -13.319620,
-0.826270, 0.888530, 0.629700, 0.006610, 0.431180, -1.013240, 1.395110, 0.970380, -0.137150, 0.796620,

1.083400, -0.191000, -1.182020, -0.291140, 0.479850, 0.816250, 0.719740, -0.533450, -1.917400, -0.166190,
-0.940580, -0.371400, 0.620340, -0.928320, 0.987010, -0.738120, 0.037930, -0.312040, -0.015650, -13.807420,
0.344230, -0.693310, 0.486310, -0.013900, 0.552000, -0.708470, 1.256740, 0.935600, 0.785590, 0.930070,

1.304710, -0.091010, -1.654540, 0.030230, 0.397820, 0.815230, 0.216170, -0.801840, -1.523560, -0.857710,
0.730200, -0.421940, 0.190540, 0.332620, 1.059310, -0.695540, -0.224470, -0.749960, -0.928150, -12.594120,
-0.910490, 0.262450, 0.218780, 0.697960, 0.685330, -0.964560, 1.182140, 0.756510, -0.997200, 0.406070,

1.175320, -0.609630, -1.800620, -0.029810, 0.346600, 0.884840, 0.498670, -0.700080, -1.633920, -0.880240,
0.685460, -0.500410, 0.651590, -0.192990, 0.867780, -0.589370, -0.188070, -0.973100, 0.540520, -12.702860,
0.856010, -0.167390, -0.809720, -0.869630, -0.234220, -1.119190, 1.142310, 0.766060, 0.383760, 0.448400,

1.099900, -0.512540, -2.200570, -0.170850, 0.617860, 0.812040, 0.450920, -0.871870, -1.293900, -1.066280,
0.263280, -0.715590, 0.194540, 0.346020, 0.903880, -0.774160, -0.525090, -0.983620, 0.201960, -11.704250,
0.277200, 0.536210, -0.724200, 0.425960, -0.797750, -1.411340, 1.139920, 0.760370, -0.280960, 0.376260,

1.021020, -0.297730, -1.880560, -0.614430, 0.301730, 0.778130, 1.094930, -0.581650, -0.987490, -0.481680,
-0.233130, -0.424560, -0.101220, 0.422110, 1.001930, 0.528300, -0.688660, -0.398940, -0.595200, -13.129710,
0.750350, -0.068980, 1.067040, -0.614220, 0.061550, -1.553460, 1.133870, 0.733200, -0.638150, 0.244530,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, -0.143470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 2 (inp2) */
      0.0, 0.559620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 3 (inp3) */
      0.0, 0.906640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 4 (inp4) */
      0.0, 0.612790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 5 (inp5) */
      0.0, 0.684560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 6 (inp6) */
      0.0, 0.300180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 7 (inp7) */
      0.0, 0.351850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 8 (inp8) */
      0.0, -0.823090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 9 (inp9) */
      0.0, -0.896550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 10 (inp10) */
      0.0, -0.824350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 11 (inp11) */
      0.0, -0.559720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 12 (inp12) */
      0.0, -0.200240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 13 (inp13) */
      0.0, 0.260870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 14 (inp14) */
      0.0, 0.425180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 15 (inp15) */
      0.0, -0.027240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 16 (inp16) */
      0.0, -0.168720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 17 (inp17) */
      0.0, 0.225140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 18 (inp18) */
      0.0, -0.667940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 19 (inp19) */
      0.0, 0.963510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 20 (inp20) */
      0.0, -0.847870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 21 (inp21) */
      0.0, -0.650360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 22 (inp22) */
      0.0, -0.581130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 23 (inp23) */
      0.0, 0.903080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 24 (inp24) */
      0.0, -0.939430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 25 (inp25) */
      0.0, -0.832650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 26 (inp26) */
      0.0, -0.376750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 27 (inp27) */
      0.0, 0.312780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 28 (inp28) */
      0.0, -0.423360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 29 (inp29) */
      0.0, -0.548100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 30 (inp30) */
      0.0, -0.585970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 31 (inp31) */
      0.0, -0.302150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 32 (inp32) */
      0.0, 0.204110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 33 (inp33) */
      0.0, 0.559170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 34 (inp34) */
      0.0, -0.290460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 35 (inp35) */
      0.0, 0.708620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 36 (inp36) */
      0.0, 0.777840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 37 (inp37) */
      0.0, 0.588660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 38 (inp38) */
      0.0, -0.783910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 39 (inp39) */
      0.0, -0.538990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 40 (inp40) */
      0.0, -0.492320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 41 (inp41) */
      0.0, 0.844890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 42 (inp42) */
      0.0, 0.366630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 43 (inp43) */
      0.0, 0.225160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 44 (inp44) */
      0.0, 0.583020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 45 (inp45) */
      0.0, -0.301320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 46 (inp46) */
      0.0, 0.076550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 47 (inp47) */
      0.0, 0.087470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 48 (inp48) */
      0.0, 0.066030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 49 (inp49) */
      0.0, 0.501070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 50 (inp50) */
      0.0, 0.935450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 51 (inp51) */
      0.0, 0.590430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 52 (inp52) */
      0.0, 0.587880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 53 (inp53) */
      0.0, 0.539640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 54 (inp54) */
      0.0, -0.173840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 55 (inp55) */
      0.0, 0.966600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 56 (inp56) */
      0.0, 0.348670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 57 (inp57) */
      0.0, 0.090710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 58 (inp58) */
      0.0, -0.866490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 59 (inp59) */
      0.0, -0.540800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 60 (inp60) */
      0.0, 0.858430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 61 (inp61) */
      0.0, -0.051240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 62 (inp62) */
      0.0, 0.218340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 63 (inp63) */
      0.0, -0.239230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 64 (inp64) */
      0.0, -0.042270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 65 (inp65) */
      0.0, 0.036760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 66 (inp66) */
      0.0, 0.452080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 67 (inp67) */
      0.0, -0.959610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 68 (inp68) */
      0.0, -0.889340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 69 (inp69) */
      0.0, -0.956220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 70 (inp70) */
      0.0, -0.684300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 71 (inp71) */
      0.0, 0.956210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 72 (inp72) */
      0.0, -0.578850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 73 (inp73) */
      0.0, -0.184040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 74 (inp74) */
      0.0, -0.434980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 75 (inp75) */
      0.0, -0.111160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 76 (inp76) */
      0.0, 0.912270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 77 (inp77) */
      0.0, -0.643090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 78 (inp78) */
      0.0, -0.327340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 79 (inp79) */
      0.0, -0.844830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 80 (inp80) */
      0.0, 0.416060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 81 (inp81) */
      0.0, 0.779820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 82 (inp82) */
      0.0, 0.313680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 83 (inp83) */
      0.0, 0.786370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 84 (inp84) */
      0.0, -0.988690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 85 (inp85) */
      0.0, 0.994460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 86 (inp86) */
      0.0, -0.075670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 87 (inp87) */
      0.0, 0.537360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 88 (inp88) */
      0.0, -0.153320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 89 (inp89) */
      0.0, 0.002650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 90 (inp90) */
      0.0, -0.091620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 91 (inp91) */
      0.0, -0.060140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 92 (inp92) */
      0.0, -0.105110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 93 (inp93) */
      0.0, 0.701630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 94 (inp94) */
      0.0, 0.186990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 95 (inp95) */
      0.0, -0.434910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 96 (inp96) */
      0.0, -0.332240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 97 (inp97) */
      0.0, 0.437700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 98 (inp98) */
      0.0, -0.999300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 99 (inp99) */
      0.0, -0.785650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 100 (inp100) */
      0.0, 0.116200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (inp101) */
      0.0, 0.186550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 102 (inp102) */
      0.0, 0.407670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 103 (inp103) */
      0.0, 0.840270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 104 (inp104) */
      0.0, 0.248900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 105 (inp105) */
      0.0, -0.769330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 106 (inp106) */
      0.0, 0.232050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 107 (inp107) */
      0.0, -0.203140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 108 (inp108) */
      0.0, -0.198290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 109 (inp109) */
      0.0, -0.779930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 110 (inp110) */
      0.0, -0.529430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 111 (inp111) */
      0.0, 0.043510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (inp112) */
      0.0, 0.416900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 113 (inp113) */
      0.0, -0.704190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 114 (inp114) */
      0.0, -0.247490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 115 (inp115) */
      0.0, 0.551740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 116 (inp116) */
      0.0, 0.060370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 117 (inp117) */
      0.0, -0.122990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 118 (inp118) */
      0.0, -0.524970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 119 (inp119) */
      0.0, -0.906150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 120 (inp120) */
      0.0, 0.092600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 121 (inp121) */
      0.0, -0.796980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 122 (inp122) */
      0.0, -0.969700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 123 (inp123) */
      0.0, -0.618690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 124 (inp124) */
      0.0, 0.765160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 125 (inp125) */
      0.0, -0.177920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 126 (inp126) */
      0.0, 0.145240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 127 (inp127) */
      0.0, -0.935420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 128 (inp128) */
      0.0, -0.344540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 129 (inp129) */
      0.0, -0.944490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 130 (inp130) */
      0.0, 0.035690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 131 (inp131) */
      0.0, -0.854230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 132 (inp132) */
      0.0, -0.637380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 133 (inp133) */
      0.0, -0.232190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 134 (inp134) */
      0.0, 0.813810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 135 (inp135) */
      0.0, -0.025440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 136 (inp136) */
      0.0, -0.176620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 137 (inp137) */
      0.0, -0.644480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 138 (inp138) */
      0.0, -0.415440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 139 (inp139) */
      0.0, -0.876280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 140 (inp140) */
      0.0, -0.010960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 141 (inp141) */
      0.0, -0.855380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 142 (inp142) */
      0.0, -0.158460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 143 (inp143) */
      0.0, -0.654300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 144 (inp144) */
      0.0, 0.927090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 145 (inp145) */
      0.0, -0.138030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 146 (inp146) */
      0.0, 0.265210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 147 (inp147) */
      0.0, 0.610490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 148 (inp148) */
      0.0, -0.767180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 149 (inp149) */
      0.0, 0.621940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 150 (inp150) */
      0.0, -0.307030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 151 (inp151) */
      0.0, -0.623520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 152 (inp152) */
      0.0, 0.987800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 153 (inp153) */
      0.0, 0.136760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 154 (inp154) */
      0.0, -0.051370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 155 (inp155) */
      0.0, -0.946340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 156 (inp156) */
      0.0, 0.380020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 157 (inp157) */
      0.0, 0.407210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 158 (inp158) */
      0.0, 0.182450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 159 (inp159) */
      0.0, -0.272260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 160 (inp160) */
      0.0, -0.026540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 161 (inp161) */
      0.0, 0.857730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 162 (inp162) */
      0.0, -0.604500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 163 (inp163) */
      0.0, -0.884360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 164 (inp164) */
      0.0, -0.083700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 165 (inp165) */
      0.0, -0.776420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 166 (inp166) */
      0.0, 0.637550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 167 (inp167) */
      0.0, -0.748920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 168 (inp168) */
      0.0, -0.986570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 169 (inp169) */
      0.0, -0.955710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 170 (inp170) */
      0.0, -0.074980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 171 (inp171) */
      0.0, -0.769020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 172 (inp172) */
      0.0, 0.431000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 173 (inp173) */
      0.0, 0.529550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 174 (inp174) */
      0.0, -0.103090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 175 (inp175) */
      0.0, -0.488480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 176 (inp176) */
      0.0, 0.193010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 177 (inp177) */
      0.0, -0.902040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 178 (inp178) */
      0.0, 0.498790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 179 (inp179) */
      0.0, 0.591000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 180 (inp180) */
      0.0, 0.879850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 181 (inp181) */
      0.0, -0.106640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 182 (inp182) */
      0.0, -0.833290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 183 (inp183) */
      0.0, -0.334820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 184 (inp184) */
      0.0, 0.828690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 185 (inp185) */
      0.0, -0.997040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 186 (inp186) */
      0.0, -0.100480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 187 (inp187) */
      0.0, 0.041580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 188 (inp188) */
      0.0, 0.410970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 189 (inp189) */
      0.0, 0.472040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 190 (inp190) */
      0.0, 0.805250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 191 (inp191) */
      0.0, 0.149270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 192 (inp192) */
      0.0, -0.158230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 193 (inp193) */
      0.0, -0.836610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 194 (inp194) */
      0.0, 0.947770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 195 (inp195) */
      0.0, -0.880470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 196 (inp196) */
      0.0, -0.355930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 197 (inp197) */
      0.0, 0.269510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 198 (inp198) */
      0.0, 0.087130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 199 (inp199) */
      0.0, -0.274570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 200 (inp200) */
      0.0, -0.997890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 201 (inp201) */
      0.0, 0.171370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 202 (inp202) */
      0.0, -0.098730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 203 (inp203) */
      0.0, 0.381330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 204 (inp204) */
      0.0, -0.583920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 205 (inp205) */
      0.0, -0.739570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 206 (inp206) */
      0.0, 0.918760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 207 (inp207) */
      0.0, 0.689310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 208 (inp208) */
      0.0, 0.405960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 209 (inp209) */
      0.0, -0.693210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 210 (inp210) */
      0.0, -0.680160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 211 (inp211) */
      0.0, -0.707180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 212 (inp212) */
      0.0, -0.433150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 213 (inp213) */
      0.0, 0.566030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 214 (inp214) */
      0.0, 0.334260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 215 (inp215) */
      0.0, 0.517840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 216 (inp216) */
      0.0, -0.419390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 217 (inp217) */
      0.0, -0.237630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 218 (inp218) */
      0.0, 0.755440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 219 (inp219) */
      0.0, -0.748610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 220 (inp220) */
      0.0, -0.663390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 221 (inp221) */
      0.0, -0.344820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 222 (inp222) */
      0.0, 0.395590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 223 (inp223) */
      0.0, 0.872520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 224 (inp224) */
      0.0, -0.924060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 225 (inp225) */
      0.0, -0.531100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 226 (inp226) */
      0.0, 0.640060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 227 (inp227) */
      0.0, 0.802280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 228 (inp228) */
      0.0, 0.382510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 229 (inp229) */
      0.0, -0.981310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 230 (inp230) */
      0.0, -0.146540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 231 (inp231) */
      0.0, 0.710760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 232 (inp232) */
      0.0, 0.306660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 233 (inp233) */
      0.0, -0.036510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 234 (inp234) */
      0.0, 0.695840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 235 (inp235) */
      0.0, -0.211430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 236 (inp236) */
      0.0, -0.705500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 237 (inp237) */
      0.0, 0.926840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 238 (inp238) */
      0.0, -0.404840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 239 (inp239) */
      0.0, -0.721080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 240 (inp240) */
      0.0, -0.248570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 241 (inp241) */
      0.0, -0.000070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 242 (inp242) */
      0.0, -0.919900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 243 (inp243) */
      0.0, -0.960590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 244 (inp244) */
      0.0, 0.801400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 245 (inp245) */
      0.0, -0.270140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 246 (inp246) */
      0.0, -0.486790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 247 (inp247) */
      0.0, 0.969710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 248 (inp248) */
      0.0, -0.606160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 249 (inp249) */
      0.0, -0.456660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 250 (inp250) */
      0.0, 0.304420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 251 (inp251) */
      0.0, 0.253980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 252 (inp252) */
      0.0, -0.393850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 253 (inp253) */
      0.0, -0.301950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 254 (inp254) */
      0.0, -0.026710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 255 (inp255) */
      0.0, -0.577090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 256 (inp256) */
      0.0, 0.507380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 257 (inp257) */
      0.0, -0.577700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 258 (inp258) */
      0.0, 0.730240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 259 (inp259) */
      0.0, 0.978750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 260 (inp260) */
      0.0, -0.025430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 261 (inp261) */
      0.0, 0.623000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 262 (inp262) */
      0.0, 0.542690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 263 (inp263) */
      0.0, 0.832610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 264 (inp264) */
      0.0, 0.540590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 265 (inp265) */
      0.0, 0.229840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 266 (inp266) */
      0.0, 0.145100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 267 (inp267) */
      0.0, 0.003530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 268 (inp268) */
      0.0, -0.174770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 269 (inp269) */
      0.0, -0.686670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 270 (hid11) */
      0.0, -0.091860, 299,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 271 (hid12) */
      0.0, 0.376080, 299,
       &Sources[299] ,
       &Weights[299] ,
      },
    { /* unit 272 (hid13) */
      0.0, -0.172010, 299,
       &Sources[598] ,
       &Weights[598] ,
      },
    { /* unit 273 (hid14) */
      0.0, 0.268760, 299,
       &Sources[897] ,
       &Weights[897] ,
      },
    { /* unit 274 (hid15) */
      0.0, -1.209790, 299,
       &Sources[1196] ,
       &Weights[1196] ,
      },
    { /* unit 275 (hid16) */
      0.0, -1.307440, 299,
       &Sources[1495] ,
       &Weights[1495] ,
      },
    { /* unit 276 (hid17) */
      0.0, -0.034270, 299,
       &Sources[1794] ,
       &Weights[1794] ,
      },
    { /* unit 277 (hid18) */
      0.0, 0.967370, 299,
       &Sources[2093] ,
       &Weights[2093] ,
      },
    { /* unit 278 (hid19) */
      0.0, 0.029080, 299,
       &Sources[2392] ,
       &Weights[2392] ,
      },
    { /* unit 279 (hid110) */
      0.0, 0.250290, 299,
       &Sources[2691] ,
       &Weights[2691] ,
      },
    { /* unit 280 (hid111) */
      0.0, 0.540460, 299,
       &Sources[2990] ,
       &Weights[2990] ,
      },
    { /* unit 281 (hid112) */
      0.0, -1.459860, 299,
       &Sources[3289] ,
       &Weights[3289] ,
      },
    { /* unit 282 (hid113) */
      0.0, -0.549810, 299,
       &Sources[3588] ,
       &Weights[3588] ,
      },
    { /* unit 283 (hid114) */
      0.0, 0.461070, 299,
       &Sources[3887] ,
       &Weights[3887] ,
      },
    { /* unit 284 (hid115) */
      0.0, 0.197680, 299,
       &Sources[4186] ,
       &Weights[4186] ,
      },
    { /* unit 285 (hid116) */
      0.0, 0.265260, 299,
       &Sources[4485] ,
       &Weights[4485] ,
      },
    { /* unit 286 (hid117) */
      0.0, -0.162820, 299,
       &Sources[4784] ,
       &Weights[4784] ,
      },
    { /* unit 287 (hid118) */
      0.0, -0.773950, 299,
       &Sources[5083] ,
       &Weights[5083] ,
      },
    { /* unit 288 (hid119) */
      0.0, -1.028840, 299,
       &Sources[5382] ,
       &Weights[5382] ,
      },
    { /* unit 289 (hid120) */
      0.0, -0.655730, 299,
       &Sources[5681] ,
       &Weights[5681] ,
      },
    { /* unit 290 (hid121) */
      0.0, 0.521240, 299,
       &Sources[5980] ,
       &Weights[5980] ,
      },
    { /* unit 291 (hid122) */
      0.0, -0.577920, 299,
       &Sources[6279] ,
       &Weights[6279] ,
      },
    { /* unit 292 (hid123) */
      0.0, -0.470160, 299,
       &Sources[6578] ,
       &Weights[6578] ,
      },
    { /* unit 293 (hid124) */
      0.0, -0.547440, 299,
       &Sources[6877] ,
       &Weights[6877] ,
      },
    { /* unit 294 (hid125) */
      0.0, 0.607460, 299,
       &Sources[7176] ,
       &Weights[7176] ,
      },
    { /* unit 295 (hid126) */
      0.0, 0.041820, 299,
       &Sources[7475] ,
       &Weights[7475] ,
      },
    { /* unit 296 (hid127) */
      0.0, 0.075620, 299,
       &Sources[7774] ,
       &Weights[7774] ,
      },
    { /* unit 297 (hid128) */
      0.0, 1.029030, 299,
       &Sources[8073] ,
       &Weights[8073] ,
      },
    { /* unit 298 (hid129) */
      0.0, 0.242330, 299,
       &Sources[8372] ,
       &Weights[8372] ,
      },
    { /* unit 299 (hid130) */
      0.0, -0.939050, 299,
       &Sources[8671] ,
       &Weights[8671] ,
      },
    { /* unit 300 (hid21) */
      0.0, -0.121420, 60,
       &Sources[8970] ,
       &Weights[8970] ,
      },
    { /* unit 301 (hid22) */
      0.0, -0.766380, 60,
       &Sources[9030] ,
       &Weights[9030] ,
      },
    { /* unit 302 (hid23) */
      0.0, -0.949230, 60,
       &Sources[9090] ,
       &Weights[9090] ,
      },
    { /* unit 303 (hid24) */
      0.0, 0.324720, 60,
       &Sources[9150] ,
       &Weights[9150] ,
      },
    { /* unit 304 (hid25) */
      0.0, -0.452280, 60,
       &Sources[9210] ,
       &Weights[9210] ,
      },
    { /* unit 305 (hid26) */
      0.0, 0.622980, 60,
       &Sources[9270] ,
       &Weights[9270] ,
      },
    { /* unit 306 (hid27) */
      0.0, 0.570310, 60,
       &Sources[9330] ,
       &Weights[9330] ,
      },
    { /* unit 307 (hid28) */
      0.0, 0.646440, 60,
       &Sources[9390] ,
       &Weights[9390] ,
      },
    { /* unit 308 (hid29) */
      0.0, -1.044320, 60,
       &Sources[9450] ,
       &Weights[9450] ,
      },
    { /* unit 309 (hid210) */
      0.0, -0.516320, 60,
       &Sources[9510] ,
       &Weights[9510] ,
      },
    { /* unit 310 (hid211) */
      0.0, -0.542340, 60,
       &Sources[9570] ,
       &Weights[9570] ,
      },
    { /* unit 311 (hid212) */
      0.0, -0.292980, 60,
       &Sources[9630] ,
       &Weights[9630] ,
      },
    { /* unit 312 (hid213) */
      0.0, 0.911730, 60,
       &Sources[9690] ,
       &Weights[9690] ,
      },
    { /* unit 313 (hid214) */
      0.0, 0.847230, 60,
       &Sources[9750] ,
       &Weights[9750] ,
      },
    { /* unit 314 (hid215) */
      0.0, -0.885820, 60,
       &Sources[9810] ,
       &Weights[9810] ,
      },
    { /* unit 315 (hid216) */
      0.0, 0.172640, 60,
       &Sources[9870] ,
       &Weights[9870] ,
      },
    { /* unit 316 (hid217) */
      0.0, -0.812430, 60,
       &Sources[9930] ,
       &Weights[9930] ,
      },
    { /* unit 317 (hid218) */
      0.0, -0.656540, 60,
       &Sources[9990] ,
       &Weights[9990] ,
      },
    { /* unit 318 (hid219) */
      0.0, -0.163060, 60,
       &Sources[10050] ,
       &Weights[10050] ,
      },
    { /* unit 319 (hid220) */
      0.0, 0.970540, 60,
       &Sources[10110] ,
       &Weights[10110] ,
      },
    { /* unit 320 (hid221) */
      0.0, -0.777630, 60,
       &Sources[10170] ,
       &Weights[10170] ,
      },
    { /* unit 321 (hid222) */
      0.0, 1.029000, 60,
       &Sources[10230] ,
       &Weights[10230] ,
      },
    { /* unit 322 (hid223) */
      0.0, 0.373280, 60,
       &Sources[10290] ,
       &Weights[10290] ,
      },
    { /* unit 323 (hid224) */
      0.0, 0.788830, 60,
       &Sources[10350] ,
       &Weights[10350] ,
      },
    { /* unit 324 (hid225) */
      0.0, -0.385330, 60,
       &Sources[10410] ,
       &Weights[10410] ,
      },
    { /* unit 325 (hid226) */
      0.0, -0.573880, 60,
       &Sources[10470] ,
       &Weights[10470] ,
      },
    { /* unit 326 (hid227) */
      0.0, -0.393030, 60,
       &Sources[10530] ,
       &Weights[10530] ,
      },
    { /* unit 327 (hid228) */
      0.0, -0.639000, 60,
       &Sources[10590] ,
       &Weights[10590] ,
      },
    { /* unit 328 (hid229) */
      0.0, 0.445070, 60,
       &Sources[10650] ,
       &Weights[10650] ,
      },
    { /* unit 329 (hid230) */
      0.0, 0.727550, 60,
       &Sources[10710] ,
       &Weights[10710] ,
      },
    { /* unit 330 (out1) */
      0.0, 0.792580, 30,
       &Sources[10770] ,
       &Weights[10770] ,
      },
    { /* unit 331 (out2) */
      0.0, 0.422820, 30,
       &Sources[10800] ,
       &Weights[10800] ,
      },
    { /* unit 332 (out3) */
      0.0, -0.731010, 30,
       &Sources[10830] ,
       &Weights[10830] ,
      },
    { /* unit 333 (out4) */
      0.0, -0.097560, 30,
       &Sources[10860] ,
       &Weights[10860] ,
      },
    { /* unit 334 (out5) */
      0.0, 0.165390, 30,
       &Sources[10890] ,
       &Weights[10890] ,
      },
    { /* unit 335 (out6) */
      0.0, 0.569620, 30,
       &Sources[10920] ,
       &Weights[10920] ,
      },
    { /* unit 336 (out7) */
      0.0, -0.146480, 30,
       &Sources[10950] ,
       &Weights[10950] ,
      },
    { /* unit 337 (out8) */
      0.0, 0.110260, 30,
       &Sources[10980] ,
       &Weights[10980] ,
      },
    { /* unit 338 (out9) */
      0.0, -0.697490, 30,
       &Sources[11010] ,
       &Weights[11010] ,
      },
    { /* unit 339 (out10) */
      0.0, -0.001090, 30,
       &Sources[11040] ,
       &Weights[11040] ,
      },
    { /* unit 340 (out11) */
      0.0, -0.502410, 30,
       &Sources[11070] ,
       &Weights[11070] ,
      },
    { /* unit 341 (out12) */
      0.0, -0.515350, 30,
       &Sources[11100] ,
       &Weights[11100] ,
      },
    { /* unit 342 (out13) */
      0.0, 0.008540, 30,
       &Sources[11130] ,
       &Weights[11130] ,
      },
    { /* unit 343 (out14) */
      0.0, -0.739810, 30,
       &Sources[11160] ,
       &Weights[11160] ,
      },
    { /* unit 344 (out15) */
      0.0, -0.950520, 30,
       &Sources[11190] ,
       &Weights[11190] ,
      },
    { /* unit 345 (out16) */
      0.0, -0.167070, 30,
       &Sources[11220] ,
       &Weights[11220] ,
      },
    { /* unit 346 (out17) */
      0.0, 0.316910, 30,
       &Sources[11250] ,
       &Weights[11250] ,
      },
    { /* unit 347 (out18) */
      0.0, -0.775920, 30,
       &Sources[11280] ,
       &Weights[11280] ,
      },
    { /* unit 348 (out19) */
      0.0, -0.488300, 30,
       &Sources[11310] ,
       &Weights[11310] ,
      },
    { /* unit 349 (out20) */
      0.0, -0.888300, 30,
       &Sources[11340] ,
       &Weights[11340] ,
      },
    { /* unit 350 (con11) */
0.33590, 0.500000, 2,
       &Sources[11370] ,
       &Weights[11370] ,
      },
    { /* unit 351 (con12) */
1.03539, 0.500000, 2,
       &Sources[11372] ,
       &Weights[11372] ,
      },
    { /* unit 352 (con13) */
0.05334, 0.500000, 2,
       &Sources[11374] ,
       &Weights[11374] ,
      },
    { /* unit 353 (con14) */
0.33550, 0.500000, 2,
       &Sources[11376] ,
       &Weights[11376] ,
      },
    { /* unit 354 (con15) */
0.55393, 0.500000, 2,
       &Sources[11378] ,
       &Weights[11378] ,
      },
    { /* unit 355 (con16) */
0.09816, 0.500000, 2,
       &Sources[11380] ,
       &Weights[11380] ,
      },
    { /* unit 356 (con17) */
0.33644, 0.500000, 2,
       &Sources[11382] ,
       &Weights[11382] ,
      },
    { /* unit 357 (con18) */
0.14139, 0.500000, 2,
       &Sources[11384] ,
       &Weights[11384] ,
      },
    { /* unit 358 (con19) */
1.33439, 0.500000, 2,
       &Sources[11386] ,
       &Weights[11386] ,
      },
    { /* unit 359 (con110) */
0.00000, 0.500000, 2,
       &Sources[11388] ,
       &Weights[11388] ,
      },
    { /* unit 360 (con111) */
0.00102, 0.500000, 2,
       &Sources[11390] ,
       &Weights[11390] ,
      },
    { /* unit 361 (con112) */
0.00951, 0.500000, 2,
       &Sources[11392] ,
       &Weights[11392] ,
      },
    { /* unit 362 (con113) */
0.37967, 0.500000, 2,
       &Sources[11394] ,
       &Weights[11394] ,
      },
    { /* unit 363 (con114) */
1.42745, 0.500000, 2,
       &Sources[11396] ,
       &Weights[11396] ,
      },
    { /* unit 364 (con115) */
0.27396, 0.500000, 2,
       &Sources[11398] ,
       &Weights[11398] ,
      },
    { /* unit 365 (con116) */
1.42833, 0.500000, 2,
       &Sources[11400] ,
       &Weights[11400] ,
      },
    { /* unit 366 (con117) */
0.00000, 0.500000, 2,
       &Sources[11402] ,
       &Weights[11402] ,
      },
    { /* unit 367 (con118) */
0.08392, 0.500000, 2,
       &Sources[11404] ,
       &Weights[11404] ,
      },
    { /* unit 368 (con119) */
0.28713, 0.500000, 2,
       &Sources[11406] ,
       &Weights[11406] ,
      },
    { /* unit 369 (con120) */
1.12514, 0.500000, 2,
       &Sources[11408] ,
       &Weights[11408] ,
      },
    { /* unit 370 (con121) */
0.30098, 0.500000, 2,
       &Sources[11410] ,
       &Weights[11410] ,
      },
    { /* unit 371 (con122) */
1.31056, 0.500000, 2,
       &Sources[11412] ,
       &Weights[11412] ,
      },
    { /* unit 372 (con123) */
0.00832, 0.500000, 2,
       &Sources[11414] ,
       &Weights[11414] ,
      },
    { /* unit 373 (con124) */
0.28593, 0.500000, 2,
       &Sources[11416] ,
       &Weights[11416] ,
      },
    { /* unit 374 (con125) */
1.19538, 0.500000, 2,
       &Sources[11418] ,
       &Weights[11418] ,
      },
    { /* unit 375 (con126) */
1.11985, 0.500000, 2,
       &Sources[11420] ,
       &Weights[11420] ,
      },
    { /* unit 376 (con127) */
1.42857, 0.500000, 2,
       &Sources[11422] ,
       &Weights[11422] ,
      },
    { /* unit 377 (con128) */
1.10436, 0.500000, 2,
       &Sources[11424] ,
       &Weights[11424] ,
      },
    { /* unit 378 (con129) */
1.42238, 0.500000, 2,
       &Sources[11426] ,
       &Weights[11426] ,
      },
    { /* unit 379 (con130) */
0.30175, 0.500000, 2,
       &Sources[11428] ,
       &Weights[11428] ,
      },
    { /* unit 380 (con21) */
0.00003, 0.500000, 2,
       &Sources[11430] ,
       &Weights[11430] ,
      },
    { /* unit 381 (con22) */
0.04939, 0.500000, 2,
       &Sources[11432] ,
       &Weights[11432] ,
      },
    { /* unit 382 (con23) */
0.05647, 0.500000, 2,
       &Sources[11434] ,
       &Weights[11434] ,
      },
    { /* unit 383 (con24) */
1.42857, 0.500000, 2,
       &Sources[11436] ,
       &Weights[11436] ,
      },
    { /* unit 384 (con25) */
0.03870, 0.500000, 2,
       &Sources[11438] ,
       &Weights[11438] ,
      },
    { /* unit 385 (con26) */
0.00000, 0.500000, 2,
       &Sources[11440] ,
       &Weights[11440] ,
      },
    { /* unit 386 (con27) */
0.99523, 0.500000, 2,
       &Sources[11442] ,
       &Weights[11442] ,
      },
    { /* unit 387 (con28) */
0.02496, 0.500000, 2,
       &Sources[11444] ,
       &Weights[11444] ,
      },
    { /* unit 388 (con29) */
0.00529, 0.500000, 2,
       &Sources[11446] ,
       &Weights[11446] ,
      },
    { /* unit 389 (con210) */
0.66637, 0.500000, 2,
       &Sources[11448] ,
       &Weights[11448] ,
      },
    { /* unit 390 (con211) */
1.38705, 0.500000, 2,
       &Sources[11450] ,
       &Weights[11450] ,
      },
    { /* unit 391 (con212) */
0.14191, 0.500000, 2,
       &Sources[11452] ,
       &Weights[11452] ,
      },
    { /* unit 392 (con213) */
0.60461, 0.500000, 2,
       &Sources[11454] ,
       &Weights[11454] ,
      },
    { /* unit 393 (con214) */
1.34175, 0.500000, 2,
       &Sources[11456] ,
       &Weights[11456] ,
      },
    { /* unit 394 (con215) */
0.09854, 0.500000, 2,
       &Sources[11458] ,
       &Weights[11458] ,
      },
    { /* unit 395 (con216) */
0.00008, 0.500000, 2,
       &Sources[11460] ,
       &Weights[11460] ,
      },
    { /* unit 396 (con217) */
0.68892, 0.500000, 2,
       &Sources[11462] ,
       &Weights[11462] ,
      },
    { /* unit 397 (con218) */
1.16012, 0.500000, 2,
       &Sources[11464] ,
       &Weights[11464] ,
      },
    { /* unit 398 (con219) */
1.42850, 0.500000, 2,
       &Sources[11466] ,
       &Weights[11466] ,
      },
    { /* unit 399 (con220) */
0.00000, 0.500000, 2,
       &Sources[11468] ,
       &Weights[11468] ,
      },
    { /* unit 400 (con221) */
1.37512, 0.500000, 2,
       &Sources[11470] ,
       &Weights[11470] ,
      },
    { /* unit 401 (con222) */
1.42217, 0.500000, 2,
       &Sources[11472] ,
       &Weights[11472] ,
      },
    { /* unit 402 (con223) */
0.95454, 0.500000, 2,
       &Sources[11474] ,
       &Weights[11474] ,
      },
    { /* unit 403 (con224) */
1.35572, 0.500000, 2,
       &Sources[11476] ,
       &Weights[11476] ,
      },
    { /* unit 404 (con225) */
1.42456, 0.500000, 2,
       &Sources[11478] ,
       &Weights[11478] ,
      },
    { /* unit 405 (con226) */
0.03587, 0.500000, 2,
       &Sources[11480] ,
       &Weights[11480] ,
      },
    { /* unit 406 (con227) */
0.01254, 0.500000, 2,
       &Sources[11482] ,
       &Weights[11482] ,
      },
    { /* unit 407 (con228) */
0.00354, 0.500000, 2,
       &Sources[11484] ,
       &Weights[11484] ,
      },
    { /* unit 408 (con229) */
1.42857, 0.500000, 2,
       &Sources[11486] ,
       &Weights[11486] ,
      },
    { /* unit 409 (con230) */
0.89812, 0.500000, 2,
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
