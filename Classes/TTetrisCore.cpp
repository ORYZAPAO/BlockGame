
#include"TTetrisCore.h"

using namespace PretyTetris;

/*
 *
 */ 
 void TCore::Resize(const int x, const int y) {
   m_Width = x; 
   m_Width = y;

   // Resize(x,y)
   m_Matrix.resize(m_Width);  m_BackMatrix.resize(m_Width);
   for (int i=0; i<m_Width; i++) {
     m_Matrix[i].resize(m_Height);  m_BackMatrix[i].resize(m_Height);
   }

   // Initialize
   for (int xx = 0; xx<m_Width; xx++) {
     for (int yy = 0; yy<m_Height; yy++) {
         m_Matrix[xx][yy] = false;  m_BackMatrix[xx][yy] = false;
     }
   }
}


 bool TCore::IsPutParts(Parts parts, const int posx, const int posy){

   for (int xx = posx; xx<m_Width; xx++) {
     for (int yy = posy; yy<m_Height; yy++) {
     }
   }
    return true;
 }

