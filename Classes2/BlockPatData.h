
  const int    _patSize_x = 5, _patSize_y = 5;

  const int    _space  =  2;
  const int    _width  = _space + 10 + _space; // 14
  const int    _height = _space + 20 + _space; // 24

  const int _base_x = _space;
  const int _base_y = _space;

  const char *_bckground_init[2 + 20 + 2]={
    "00000000000000"
   ,"00000000000000"
   ,"00..........00"
   ,"00..........00"
   ,"00..........00"
   ,"00..........00"
   ,"00..........00"
   ,"00..........00"
   ,"00..........00"
   ,"00..........00"
   ,"00..........00"
   ,"00..........00"
   ,"00..........00"
   ,"00..........00"
   ,"00..........00"
   ,"00..........00"
   ,"00..........00"
   ,"00..........00"
   ,"00..........00"
   ,"00..........00"
   ,"00..........00"
   ,"00..........00"
   ,"00000000000000"
   ,"00000000000000"
  };


  char _bckground[2 + 20 + 2][2 + 10 + 2];
  char _output[2 + 20 + 2][2 + 10 + 2];

  const char *_blkPatten_Bar[20]={
    "..0.."
   ,"..0.."
   ,"..0.."
   ,"..0.."
   ,"....."

   ,"....."
   ,"....."
   ,"0000."
   ,"....."
   ,"....."

   ,"....."
   ,"..0.."
   ,"..0.."
   ,"..0.."
   ,"..0.."

   ,"....."
   ,"....."
   ,".0000"
   ,"....."
   ,"....."  };

  const char *_blkPatten_L[20] = {
    "....."
   ,"..0.."
   ,"..0.."
   ,"..00."
   ,"....."

   ,"....."
   ,"...0."
   ,".000."
   ,"....."
   ,"....."

   ,"....."
   ,".00.."
   ,"..0.."
   ,"..0.."
   ,"....."
  
   ,"....."
   ,"....."
   ,".000."
   ,".0..."
   ,"....." };

  const char *_blkPatten_RevL[20] = {
    "....."
   ,"..0.."
   ,"..0.."
   ,".00.."
   ,"....."

   ,"....."
   ,"....."
   ,".000."
   ,"...0."
   ,"....."

   ,"....."
   ,"..00."
   ,"..0.."
   ,"..0.."
   ,"....."

   ,"....."
   ,".0..."
   ,".000."
   ,"....."
   ,"....."  };

  const char *_blkPatten_Z[20] = {
    "....."
   ,".00.."
   ,"..00."
   ,"....."
   ,"....."

   ,"....."
   ,"..0.."
   ,".00.."
   ,".0..."
   ,"....."

   ,"....."
   ,"....."
   ,".00.."
   ,"..00."
   ,"....."

   ,"....."
   ,"...0."
   ,"..00."
   ,"..0.."
   ,"....." };

  const char *_blkPatten_RevZ[20] = {
    "....."
   ,"..00."
   ,".00.."
   ,"....."
   ,"....."

   ,"....."
   ,".0..."
   ,".00.."
   ,"..0.."
   ,"....."

   ,"....."
   ,"....."
   ,"..00."
   ,".00.."
   ,"....."

   ,"....."
   ,"..0.."
   ,"..00."
   ,"...0."
   ,"....." };

  const char *_blkPatten_Totsu[20] = {
    "....."
   ,"..0.."
   ,".000."
   ,"....."
   ,"....."
    
   ,"....."
   ,"..0.."
   ,".00.."
   ,"..0.."
   ,"....."

   ,"....."
   ,"....."
   ,".000."
   ,"..0.."
   ,"....." 

   ,"....."
   ,"..0.."
   ,"..00."
   ,"..0.."
   ,"....."  };
