#include<iostream>
#include<boost/format.hpp>

#include<cstdio>

using namespace std;

#include "TCore.h"




int main(){
  char k;
  tinytetris::TCore tcore;
  tinytetris::Block blk{ tinytetris::Parts::Totsu, 1, 2, 2};  

  tcore.DbgPrint(blk); 
  getchar();  

  bool pre_down = false;
  bool down = false;
  while(1){

    k = getchar();  tcore.DbgPrint(blk);

    if( tcore.ClearLine() ){
      cout << "HIT!!" <<endl;
    } 

    if      ( k == 'k' ){
      tcore.TurnBlock(blk);
      down = true;
    }else if( k == 's' ){
      tcore.MoveBlock(blk, true);
      down = true;
    }else if( k == 'd' ){      
      tcore.MoveBlock(blk, false);
      down = true;
    }else{      

      pre_down = down;
      down     = tcore.TakeDownBlock(blk);
      if( (!pre_down) && (!down) ){
        tcore.PutPartsToBckGround(blk);
        blk = {tinytetris::Parts::Totsu, 0, 2,2};
      }
    }
  }
  

}
