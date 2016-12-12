
#include <cassert>

#include"TTetrisCore.h"

using namespace PrityTetris;

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


/* Collision Check
 *
 */
 bool TCore::IsCollision(Parts partsNo, const int posx, const int posy){

   const char **p;
   bool retcode;
   
   //enum Parts { Bar=0, L=1, RevL=2, Z=3, RevZ=4, Totsu=5};
   //const char* m_Pat_Bar[20]={
   if     ( partsNo == Parts::Bar   ) p = m_Pat_Bar;
   else if( partsNo == Parts::L     ) p = m_Pat_L;
   else if( partsNo == Parts::RevL  ) p = m_Pat_RevL;
   else if( partsNo == Parts::Z     ) p = m_Pat_Z;
   else if( partsNo == Parts::RevZ  ) p = m_Pat_RevZ;
   else if( partsNo == Parts::Totsu ) p = m_Pat_Totsu;
   else  p = nullptr;
   assert( p != nullptr);
   
   retcode = false;
   for (int xx = 0; xx<PartsSizeX; xx++) {
     for (int yy =0; yy<PartsSizeY; yy++) {

       // Check Over
       if( ((posx+xx) >= m_Width ) ||
           ((posy+yy) >= m_Height) ){ goto END; }
       
       // Judge Collision
       if( (p[xx][yy] == '0') && (m_Matrix[posx+xx][posy+yy]==true) ){ goto END;}
     }
   }
   retcode = true;
   
 END:
   return retcode;
 }

