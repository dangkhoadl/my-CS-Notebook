
// Output = True/False
// Input = Probability of True
//      Eg: P(true) = 0.8
bool randTrueFalse(double prob) {
    return rand() <  prob * (static_cast<double>(RAND_MAX) + 1.0);
}
