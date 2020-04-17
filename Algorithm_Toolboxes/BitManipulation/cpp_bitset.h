
// set x - element k in x:
//      Init set:                                              			bitset<365> x("101");
//      Add element k to set:                                        	x.set(k);				x[k] = true;
//      Check if element k is in set:                                	x.test(k)				x[k]
//      Remove element k out of set:                                	x.reset(k);				x[k] = false;
//      Toggle element k:                                           	x.flip(k);
//      Return x size (number of bit 1)                             	x.count()

// Set Operations set z, set x, set y:
//      Union:                                              z = x | y
//      Intersection:                                       z = x & y
//      Complement:                                         y = ~x
//      Diference (x\y):                                    z = x & (~y)

// Print bitset												x.to_string()
