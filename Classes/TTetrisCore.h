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
    Parts _Number;
    int   _SubNum;
  
    Block(Parts Num=Parts::Bar, int subNum=0):_Number(Num), _SubNum(subNum){}
  };
  
  
  //
  class TCore {
  
    const char *m_Pat_Bar[20]={
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

  const char *m_Pat_L[20] = {
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

  const char *m_Pat_RevL[20] = {
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

  const char *m_Pat_Z[20] = {
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

  const char *m_Pat_RevZ[20] = {
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

  const char *m_Pat_Totsu[20] = {
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

   int m_Width;
   int m_Height;

   const int PartsSizeX=5, PartsSizeY=5;
  
   std::vector< std::vector<int> >  m_Matrix;
   std::vector< std::vector<int> >  m_BackMatrix;

public:
    TCore(const int x=10, const int y=20):m_Width(x), m_Height(y){
      Resize(x,y);
    }
    ~TCore() {}

    void         Resize(const int x, const int y);
    int          GetWidth() { return m_Width;  }
    int          GetHeight(){ return m_Height; }
    const char** GetBlockData(Block &blk);
    bool         IsCollision(Block blk, const int x, const int y);
    void         PutBlock(Block blk,  const int posx, const int posy);
    bool         IsRemovingBlock();
    
    std::vector< std::vector<int> > *GetMatrics(){ return &m_Matrix; }

  };

}; /// namespace PrettyTetris{

#endif // __TTETRISCORE_H

