
#include <cassert>

#include"TTetrisCore.h"

using namespace PrettyTetris;

/* --------------------------------------------------
 *
 * ------------------------------------------------ */
 void TCore::Resize(const int x, const int y) {
   m_Width = x; 
   m_Height = y;

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


/* --------------------------------------------------
 * Get Block Data Pointer
 *
 * ------------------------------------------------ */
const char** TCore::GetBlockData(Block &blk){
  const char **p;
  
  /// Select Parts
  if     ( blk._Number == Parts::Bar   ) p = m_Pat_Bar;
  else if( blk._Number == Parts::L     ) p = m_Pat_L;
  else if( blk._Number == Parts::RevL  ) p = m_Pat_RevL;
  else if( blk._Number == Parts::Z     ) p = m_Pat_Z;
  else if( blk._Number == Parts::RevZ  ) p = m_Pat_RevZ;
  else if( blk._Number == Parts::Totsu ) p = m_Pat_Totsu;
  else  p = nullptr;
  assert( p != nullptr);
  
  /// Select PartsSubType
  p += ( PartsSizeY * blk._SubNum );
  
  return p;
}


/* --------------------------------------------------
 * Judge Collision
 *
 * ------------------------------------------------ */
bool TCore::IsCollision(Block blk, const int posx, const int posy){
  const char **p;
  bool retcode;
   
  // Block
  p = GetBlockData(blk);
   
  // Judge Collision
  retcode = false;
  for (int xx = 0; xx<PartsSizeX; xx++) {
    for (int yy =0; yy<PartsSizeY; yy++) {
      // Check Over
      if( p[xx][yy] == '0' ){
        if( ((posx+xx) >= m_Width ) ||
            ((posy+yy) >= m_Height) ){ goto END; }
       
        // Judge Collision
        if( m_Matrix[posx+xx][posy+yy] == true ){ goto END;}
      }
    }
  }
  retcode = true;

  //
 END:
   return retcode;
}


/* --------------------------------------------------
 * Put Block
 *
 * Write Block Image in Matrix
 * ------------------------------------------------ */
void TCore::PutBlock(Block blk, const int posx, const int posy){
  
  if( !IsCollision(blk, posx, posy) ) return;

  const char **p = GetBlockData(blk);

  for(int xx=0; xx<PartsSizeX; xx++){
    if( (posx+xx) >= m_Width ) continue;
    
    for(int yy=0; yy<PartsSizeY; yy++){
      if( (posy+yy) >= m_Height ) continue;

      if( p[xx][yy] == '0' ){
        m_Matrix[xx+posx][yy+posy] = true;
      }
    }
  }

END:
  return;
}


/* --------------------------------------------------
 * IsRemovingBlock
 *
 * Check if Remove the block
 * ------------------------------------------------ */
bool  TCore::IsRemovingBlock(){
  return false;
}
