string intToRoman(int num) {
        
   // struct contains an integer and a pointer pointing to constant numeral     
  struct romandata_t { int num; char const* numeral; }; 
  
  // define a constant array of structure romandata??
  static romandata_t const romandata[] = 
     { 1000, "M",    
        900, "CM",
        500, "D",
        400, "CD",
        100, "C",
         90, "XC",
         50, "L",
         40, "XL",
         10, "X",
          9, "IX",
          5, "V",
          4, "IV",
          1, "I",
          0, NULL }; // end marker, double quote for string, single quote for char
 
  string result;
  
  for (romandata_t const* current = romandata; current->num > 0; ++current)
  {
    while (num >= current->num)
    {
      result += current->numeral;
      num  -= current->num;
    }
  }
  return result;
        
    }
