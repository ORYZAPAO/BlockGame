
#include <cassert>

#include"TTetrisCore.h"

using namespace PrettyTetris;


// --------------------------------------------------
// --------------------------------------------------
void TCore::Initialize(bool surface){
  // Initialize


  /// 最初に，ブロックで敷き詰める
  for (int xx = 0; xx<_width; xx++) {
    for (int yy = 0; yy<_height; yy++) {

      if (surface)  _matrix0[xx][yy] = true;
      else          _matrix1[xx][yy] = true;
    }
  }

  /// 中のブロックを取り除く．
  for (int xx = _space; xx<(_width- _space); xx++) {
    ///for (int yy = _space; yy<(_height- _space); yy++) {
    for (int yy = _space; yy<(_height- _space)-1; yy++) {//////////////

      if( surface )  _matrix0[xx][yy] = false;
      else           _matrix1[xx][yy] = false;
    }
  }

}

// --------------------------------------------------
// --------------------------------------------------
 void TCore::Resize(const int x, const int y) {
   _width = x; 
   _height = y;

   // Resize(x,y)
   _matrix0.resize(_width);   _matrix1.resize(_width);

   //
   for (int xx=0; xx<_width; xx++) {
     _matrix0[xx].resize(_height);  _matrix1[xx].resize(_height);
   }

   // Initialize
   Initialize(true);  Initialize(false);
}



// --------------------------------------------------
// Get Block Data Pointer
//
// --------------------------------------------------
const char** TCore::GetBlockImage(const Block &blk){
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


// --------------------------------------------------
// Judge Collision
//
// ------------------------------------------------ */
bool TCore::IsCollision(const Block &blk, const int posx, const int posy){
  const char  **p;
  bool          retcode=true;
   
  // Block
  p = GetBlockImage(blk);
   
  //
  for (int xx = 0; xx<PatSizeX; xx++) {
    for (int yy =0; yy<PatSizeY; yy++) {
      // Check Out ofrange
      if( ((posx+xx) >= _width ) ||
          ((posy+yy) >= _height) ){ goto END; }
       
      // Judge Collision
      if (p[yy][xx] == '0') {
        if( _matrix0[posx+xx][posy+yy] == true ){ goto END;}
      }
    }
  }
  retcode = false;

  //
 END:
   return retcode;
}


// --------------------------------------------------
//  Turn()
//
// --------------------------------------------------
void TCore::Turn() {
  Block pre_turned_block = _currentBlock;

  pre_turned_block.Turn();
  if( IsCollision(pre_turned_block, _pos_x, _pos_y ) ){
    return;
  }

  //
  _currentBlock = pre_turned_block;
  return;
}


/* --------------------------------------------------
 * Copy1to0
 *
 * Copy _matrix1 to _matrix0
 * ------------------------------------------------ */
void TCore::Copy1to0(){
  for (int xx = _base_x; xx<(_width-_base_x); xx++) {
    for (int yy = _base_y; yy<(_height-_base_y); yy++) {
      _matrix0[xx][yy] =  _matrix0[xx][yy] | _matrix1[xx][yy];
    }
  }    
}


/* --------------------------------------------------
 * Put Block
 *
 * Write Block Image in Matrix
 * ------------------------------------------------ */
bool TCore::PutBlock(const Block &blk,
  const int dx, const int dy,     // incremental Value
  bool      surface) { // surface=0:, 1:

  bool ret_code = false;

  int next_posx = _pos_x;
  int next_posy = _pos_y;

  //
  if ( IsCollision(blk, _pos_x+dx, _pos_y+dy) == false){
    next_posx += dx;
    next_posy += dy;
    ret_code = true;
  }

  const char **p = GetBlockImage(blk);

  for (int xx = 0; xx<PatSizeX; xx++) {
    if ((next_posx + xx) >= _width) continue;

    for (int yy = 0; yy<PatSizeY; yy++) {
      if ((next_posy + yy) >= _height) continue;

      if (p[yy][xx] == '0') {
        if (surface) _matrix0[xx + next_posx][yy + next_posy] = true;
        else         _matrix1[xx + next_posx][yy + next_posy] = true;
      }
    }
  }

  //
  _pos_x = next_posx;
  _pos_y = next_posy;

END:
  return(ret_code);
}


/* --------------------------------------------------
 * IsFilledLine
 *
 * This is called by RemoveLine()
 * ------------------------------------------------ */
bool  TCore::IsFilledLine(int yy){
  int   count;
  bool  ret_code=false;

  count = 0;
  for(int xx=(_base_x); xx<(_width-_base_x); xx++){
    if( _matrix0[xx][yy] ) count++;
  }
  
  if( count >= (_width-(_base_x*2)) ){
    ret_code= true;
  }

 END:;  
  return ret_code;
}


/* --------------------------------------------------
 * DownLine
 *
 * Take down the filled line
 * This is called by RemoveLine()
 * ------------------------------------------------ */
void TCore::DownLine(int y){

  // Take Down Line
  for(int yy = y; yy>(_base_y); yy--){
    for(int xx=(_base_x); xx<(_width-_base_x); xx++){
      _matrix0[xx][yy] = _matrix0[xx][yy-1];
    }
  }

  // Remove Top Line
  for(int xx=_base_x; xx<(_width-_base_x); xx++){
    _matrix0[xx][_base_y] = false ;
  }

}  


/* --------------------------------------------------
 * RemoveLine
 *
 * 
 * ------------------------------------------------ */
void TCore::RemoveLine(){
  for(int yy=(_width - _base_y)-1; yy>=(_base_y); yy--){
    if( IsFilledLine(yy) ) DownLine(yy);
  }
}
  

/* --------------------------------------------------
 * NextStep
 *
 * ------------------------------------------------ */
void TCore::NextStep(){
  RemoveLine();

  // Clear and Redraw Block Image in _matrix1
  Initialize(false);
  if( PutBlock(_currentBlock, 0, 1, false) == false){ /// Take Down _pos_y+1
    Copy1to0();
  }
}
