#include<iostream>
#include"TCore.h"

#include<boost/format.hpp>

using namespace tinytetris;

//
//
void TCore::Initialize(){
    
  for(int yy=0; yy<_height; yy++){
    for(int xx=0; xx<_width; xx++){
      _bckground[yy][xx] =  _bckground_init[yy][xx];
    }
  }  

}


// Return Block Image
//
//
const char** TCore::GetPartsImage(const Block &blk){
  const char **pat;

  switch( blk._parts ){
  case 0: pat = _blkPatten_Bar;    break;
  case 1: pat = _blkPatten_L;      break;
  case 2: pat = _blkPatten_RevL;   break;
  case 3: pat = _blkPatten_Z;      break;    
  case 4: pat = _blkPatten_RevZ;   break;
  case 5: pat = _blkPatten_Totsu;  break;
  }
  
  return( pat + (blk._turn * _patSize_y) );
}


// Judge Collision
//
//
bool TCore::IsCollision(const Block &blk){  
  bool ret=false;

  const char **p = GetPartsImage(blk);
    
  for(int y=0; y<_patSize_y; y++){
    for(int x=0; x<_patSize_x; x++){
      if( (p[y][x] == '0') && (_bckground[blk._pos_y + y][blk._pos_x + x] == '0') ){        
        ret=true;
        goto END;
      }
    }
  }

    
 END:
  return(ret);
}


// Put Parts to _bckground
//
//
bool TCore::PutPartsToBckGround(const Block &blk){
  bool ret=false;
  const char **p;

  if( IsCollision(blk) ) goto END;

  p = GetPartsImage(blk);
  for(int x=0; x<_patSize_x; x++){
    for(int y=0; y<_patSize_y; y++){
      if( p[y][x] == '0' ){ 
        _bckground[blk._pos_y+y][blk._pos_x + x] = '0';
      }
    }
  }

 END:  
  return(ret);
}


// Check Filled Line.
//
//
bool TCore::IsFilledLine(int posy){

  bool ret=false;
  
  for(int xx=_base_x; xx<(_width-_space); xx++){    
    if( _bckground[posy][xx] == '.' ) goto END;
  }
  ret = true;
  
END:
    return ret;  
}


// Clear a filed line, 
// Take down the lines.
//
void TCore::TakeDownLine(int posy){
  for(int yy=posy; yy>=_base_y; yy--){
    for(int xx=_base_x; xx<(_width-_space); xx++){
      if( yy == _base_y ) _bckground[yy][xx] = '.';
      else                _bckground[yy][xx] = _bckground[yy-1][xx];
    }
  }

  return;
}


// 
//
//
bool TCore::ClearLine(){
  bool ret=false;

  for(int yy=(_height-_space -1); yy >= _base_y; yy--){
    if( IsFilledLine(yy) ){
      TakeDownLine(yy);
      ret = true;
    }
  }

  return ret;
}
  
////////////////////////////////////////////////////////////
// Game
////////////////////////////////////////////////////////////


//
//
//
bool TCore::TakeDownBlock(Block &blk){
  bool ret=false;
  Block tmp_blk = blk;

  (tmp_blk._pos_y)++;  
  if( IsCollision(tmp_blk) ) goto END;

  ret=true;
  blk._pos_y++;
  
 END:
  return ret;  
}  


//
//
//
bool TCore::TurnBlock(Block &blk){
  bool ret=false;
  Block tmp_blk = blk;

  tmp_blk._turn = (tmp_blk._turn+1) % 4; // 0,1,2,3,0,1,2,3... 
  if( IsCollision(tmp_blk) ) goto END;

  ret=true;
  blk = tmp_blk;

 END:  
  return ret;
}


//
//
//
bool TCore::MoveBlock(Block &blk, bool dir){
  bool   ret=false;
  Block  tmp_blk = blk;
  int    next_pos_x;

  if( dir ){ /// <-- Move Left
    next_pos_x = tmp_blk._pos_x - 1;
    tmp_blk._pos_x = (next_pos_x >= 0) ? next_pos_x
                                       : tmp_blk._pos_x;
  }else{     ///     Move Right -->
    next_pos_x = tmp_blk._pos_x + 1;
    tmp_blk._pos_x = (next_pos_x < ( _base_x + _width + _space)) ? next_pos_x
                                                                 : tmp_blk._pos_x;    
  }

  if( IsCollision(tmp_blk) ) goto END;

  ret = true;
  blk = tmp_blk;

 END:  
  return ret;
}




////////////////////////////////////////////////////////////
// Debug Print
//
//
void TCore::DbgPrint(const Block &blk){
  const char **p = GetPartsImage(blk);
  char         tmp_output[2 + 20 + 2][2 + 10 + 2];

  // Background
  for(int yy=0; yy<_height; yy++){
    for(int xx=0; xx<_width; xx++){
      tmp_output[yy][xx] =  _bckground[yy][xx];
    }
  }

  // Parts
  for(int yy=0; yy<_patSize_y; yy++){
    for(int xx=0; xx<_patSize_x; xx++){

      if( p[yy][xx]=='0'){
        tmp_output[blk._pos_y + yy][blk._pos_x + xx] = '0';
      }

    }
  }

  // Print
  for(int yy=0; yy<_height; yy++){
    for(int xx=0; xx<_width; xx++){
      std::cout << tmp_output[yy][xx];
    }
    std::cout << std::endl;
  }

}


//
//
//
void TCore::DbgPrintBlk(const Block &blk){
  std::cout << boost::format("P(%d), Num(%d), (%d,%d)\n")
    % blk._parts % blk._turn
    % blk._pos_x % blk._pos_y;
}



//bool TCore::MakeOutput(const Block &blk, const int posx, const int posy){
  
//}
