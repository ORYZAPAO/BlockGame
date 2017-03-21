#ifndef __TCORE_H__
#define __TCORE_H__

namespace tinytetris{

  
  // _bckground[0-(_width-1)] [0-(_heght-1)]
  // _freground [0-(_width-1)] [0-(_heght-1)]
  //
  //  |<<-------< _width >------->>|
  //
  //  (0, 0)-----------------------+  -+-
  //  |                            |   |
  //  |  (_base_x, _base_y)-----+  |   |
  //  |  |                      |  |   |_
  //  |  |                      |  |   |h
  //  |  |                      |  |   |e
  //  |  |                      |  |   |i
  //  |  |  (_posx, _posy)      |  |   |g
  //  |  |    o                 |  |   |h
  //  |  |   ooo                |  |   |t
  //  |  |                      |  |   |
  //  |  |                      |  |   |
  //  |  +----------------------+  |   |
  //  |                            |   |
  //  +---------------------------(_width-1, _height-1)
  //

//
enum Parts { Bar=0, L=1, RevL=2, Z=3, RevZ=4, Totsu=5};

 struct Block{
   Parts _parts;
   int   _turn;
   int   _pos_x;
   int   _pos_y;
 };
 
  
 class TCore{

 private:   
   #include"BlockPatData.h"
         
 public:     
   TCore(): _base_x(_space), _base_y(_space){
     Initialize();
   }
   ~TCore(){return;}
   
   void         Initialize();
   const char **GetPartsImage(const Block &blk);
   bool         IsCollision(const Block &blk);
   bool         PutPartsToBckGround(const Block &blk);

   bool         IsFilledLine(int posy);
   void         TakeDownLine(int posy);
   bool         ClearLine();

   bool         TakeDownBlock(Block &blk);
   bool         TurnBlock(Block &blk);
   bool         MoveBlock(Block &blk, bool dir);
   
   /// 
   void         DbgPrint(const Block &blk);
   void         DbgPrintBlk(const Block &blk);

   
 }; // class TCore{
 
 
}; // namespace tinytetris{




#endif // __TCORE_H__
