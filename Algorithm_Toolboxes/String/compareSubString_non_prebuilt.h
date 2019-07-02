

//     O(n)
// s1 = Test
// s2 = testTesttesT
//   cmpsubString(
//        s1,0,4,
//        s2,4,8) = true

bool cmpsubString(
        const string &s1, int start1, int end1, 
        const string &s2, int start2, int end2) {
    assert(start1 >= 0 and start1 < end1 and end1 <= s1.size());
    assert(start2 >= 0 and start2 < end2 and end2 <= s2.size());

    if((end1 - start1) != (end2 - start2))
        return false;

    for(int i = 0; i < (end1-start1); ++i) {
        if(s1[i+start1] != s2[i+start2])
            return false;
    }
    return true;
}
