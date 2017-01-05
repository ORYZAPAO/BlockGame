#pragma once
#ifndef __TTETRISCORE_H
#define __TTETRISCORE_H

#include<vector>	

namespace PrettyTetris{

  //
  enum Parts { Bar=0, L=1, RevL=2, Z=3, RevZ=4, Totsu=5};

  //
  class Block{
  public:
    Parts _number;
    int   _subNum;
  
    Block(Parts Num=Parts::Bar, int subNum=0):_number(Num), _subNum(subNum){}
  };
  
  
  //
  class TCore {
  
    const char *_blkPatten_Bar[20]={
    "..0..",
    "..0..",
    "..0..",
    "..0..",
    ".....",

    ".....",
    ".....",
    "0000.",
    ".....",
    ".....",

    ".....",
    "..0..",
    "..0..",
    "..0..",
    "..0..",

    ".....",
    ".....",
    ".0000",
    ".....",
    "....."  };

  const char *_blkPatten_L[20] = {
    ".....",
    "..0..",
    "..0..",
    "..00.",
    ".....",

    ".....",
    "...0.",
    ".000.",
    ".....",
    ".....",

    ".....",
    ".00..",
    "..0..",
    "..0..",
    ".....",
  
    ".....",
    ".....",
    ".000.",
    ".0...",
    "....." };

  const char *_blkPatten_RevL[20] = {
    ".....",
    "..0..",
    "..0..",
    ".00..",
    ".....",

    ".....",
    ".....",
    ".000.",
    "...0.",
    ".....",

    ".....",
    "..00.",
    "..0..",
    "..0..",
    ".....",

    ".....",
    ".0...",
    ".000.",
    ".....",
    "....."  };

  const char *_blkPatten_Z[20] = {
    ".....",
    ".00..",
    "..00.",
    ".....",
    ".....",

    ".....",
    "..0..",
    ".00..",
    ".0...",
    ".....",

    ".....",
    ".....",
    ".00..",
    "..00.",
    ".....",

    ".....",
    "...0.",
    "..00.",
    "..0..",
    "....." };

  const char *_blkPatten_RevZ[20] = {
    ".....",
    "..00.",
    ".00..",
    ".....",
    ".....",

    ".....",
    ".0...",
    ".00..",
    "..0..",
    ".....",

    ".....",
    ".....",
    "..00.",
    ".00..",
    ".....",

    ".....",
    "..0..",
    "..00.",
    "...0.",
    "....." };

  const char *_blkPatten_Totsu[20] = {
    ".....",
    "..0..",
    ".000.",
    ".....",
    ".....",
    
    ".....",
    "..0..",
    ".00..",
    "..0..",
    ".....",

    ".....",
    ".....",
    ".000.",
    "..0..",
    ".....", 

    ".....",
    "..0..",
    "..00.",
    "..0..",
    "....."  };

   int       _width;
   int       _height;

   const int PatSizeX=5, PatSizeY=5;
  
public:
   std::vector< std::vector<bool> >  _matrix0;
   std::vector< std::vector<bool> >  _matrix1;

public:
    TCore(const int x=10, const int y=20):_width(x), _height(y){
      Resize(x,y);
    }
    ~TCore() {}

    void         Resize(const int x, const int y);
    void         Initialize(bool surface);
    int          GetWidth() { return _width;  }
    int          GetHeight(){ return _height; }
    const char** GetBlockImage(Block &blk);
    bool         IsCollision(Block &blk, const int x, const int y);
    void         PutBlock(Block &blk, const int posx, const int posy, bool  surface);
    bool         IsRemovingBlock();
    
    ///std::vector< std::vector<bool> > *GetMatrics(){ return &_matrix0; }

  };

}; /// namespace PrettyTetris{

#endif // __TTETRISCORE_H

