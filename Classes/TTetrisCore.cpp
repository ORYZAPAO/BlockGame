
#include <cassert>

#include"TTetrisCore.h"

using namespace PrettyTetris;

/* --------------------------------------------------
 *
 * ------------------------------------------------ */
 void TCore::Resize(const int x, const int y) {
   _width = x; 
   _height = y;

   // Resize(x,y)
   _matrix.resize(_width); 
   for (int xx=0; xx<_width; xx++) {
     _matrix[xx].resize(_height);  
   }

   // Initialize
   for (int xx = 0; xx<_width; xx++) {
     for (int yy = 0; yy<_height; yy++) {
         _matrix[xx][yy] = false;  
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
  if     ( blk._number == Parts::Bar   ) p = _blkPatten_Bar;
  else if( blk._number == Parts::L     ) p = _blkPatten_L;
  else if( blk._number == Parts::RevL  ) p = _blkPatten_RevL;
  else if( blk._number == Parts::Z     ) p = _blkPatten_Z;
  else if( blk._number == Parts::RevZ  ) p = _blkPatten_RevZ;
  else if( blk._number == Parts::Totsu ) p = _blkPatten_Totsu;
  else  p = nullptr;
  assert( p != nullptr);
  
  /// Select PartsSubType
  p += ( PatSizeY * blk._subNum );
  
  return p;
}


/* --------------------------------------------------
 * Judge Collision
 *
 * ------------------------------------------------ */
bool TCore::IsCollision(Block &blk, const int posx, const int posy){
  const char **p;
  bool retcode;
   
  // Block
  p = GetBlockData(blk);
   
  //
  retcode = false;
  for (int xx = 0; xx<PatSizeX; xx++) {
    for (int yy =0; yy<PatSizeY; yy++) {
      // Check Out ofrange
      if( ((posx+xx) >= _width ) ||
          ((posy+yy) >= _height) ){ goto END; }
       
      // Judge Collision
      if (p[yy][xx] == '0') {
        if( _matrix[posx+xx][posy+yy] == true ){ goto END;}
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
void TCore::PutBlock(Block &blk, const int posx, const int posy){

  if( !IsCollision(blk, posx, posy) ) return;

  const char **p = GetBlockData(blk);

  for(int xx=0; xx<PatSizeX; xx++){
    if( (posx+xx) >= _width ) continue;
    
    for(int yy=0; yy<PatSizeY; yy++){
      if( (posy+yy) >= _height ) continue;

      if( p[yy][xx] == '0' ){
        _matrix[xx+posx][yy+posy] = true;
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
