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
  
    Block(Parts Num=Parts::Totsu, int subNum=0):_number(Num), _subNum(subNum){}
    void Set(Parts Num, int subNum) {
      _number=Num; _subNum=subNum;
    }

    void Turn() {
      _subNum = (_subNum + 1) % 4;
    }

  };
  

  // _matrix0 [0-(_width-1)] [0-(_heght-1)]
  // _matrix1 [0-(_width-1)] [0-(_heght-1)]
  //
  //  |<<-------<width>---------->>|
  //
  //  (0, 0)-----------------------+  -+-
  //  |                            |   |
  //  |  (_base_x, _base_y)-----+  |   |
  //  |  |                      |  |   |
  //  |  |                      |  |   |h
  //  |  |                      |  |   |e
  //  |  |                      |  |   |i
  //  |  |  (_posx, _posy)      |  |   |g
  //  |  |        o             |  |   |h
  //  |  |       ooo            |  |   |t
  //  |  |                      |  |   |
  //  |  |                      |  |   |
  //  |  +----------------------+  |   |
  //  |                            |   |
  //  +----------------------------+  -+-
  //
  class TCore {

   #include"BlockPatData.h"

   const int    PatSizeX = 5, PatSizeY = 5;
   
   int          _width;
   int          _height;

public:
   int          _base_x = 2;
   int          _base_y = 2;

   int          _pos_x = 2;
   int          _pos_y = 2;

   Block        _currentBlock;
   std::vector< std::vector<bool> >  _matrix0;
   std::vector< std::vector<bool> >  _matrix1;

public:
    TCore(const int x=10+4, const int y=20+4):_width(x), _height(y){
      Resize(x,y);
    }
    ~TCore() {}

    void         Resize(const int x, const int y);
    void         Initialize(bool surface);
    int          GetBaseX()     { return _base_x;  }
    int          GetBaseY()     { return _base_y;  }

    int          SetPosX(int x) { return _pos_x=x; }
    int          SetPosY(int y) { return _pos_y=y; }
    int          GetPosX()      { return _pos_x;   }
    int          GetPosY()      { return _pos_y;   }
    int          GetWidth()     { return _width;   }
    int          GetHeight()    { return _height;  }
    const char** GetBlockImage(const Block &blk);
    bool         IsCollision(const Block &blk, const int x, const int y);
    void         Turn();
    bool         PutBlock(const Block &blk, const int dx, const int dy, bool surface);

    bool         IsRemovingBlock();
    
    ///std::vector< std::vector<bool> > *GetMatrics(){ return &_matrix0; }

  };

}; /// namespace PrettyTetris{

#endif // __TTETRISCORE_H

