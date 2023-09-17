#include<vector>

using namespace std;

// Its kinda shitty task when scales is came from outside and you need to act like blind cat so 

unsigned int findBall(Scales& scales) {
    int idx = -1;
    int w = scales.getWeight({0, 1, 2}, {3, 4, 5});
    if (w > 0) {
        w = scales.getWeight({3}, {4});
        if (w > 0) {
            idx = 4;
        } else if (w < 0) {
            idx = 3;
        } else {
            idx = 5;
        }
    } else if (w < 0) {
        w = scales.getWeight({0}, {1});
        if (w > 0) {
            idx = 1;
        } else if (w < 0) {
            idx = 0;
        } else {
            idx = 2;
        }
    } else {
        w = scales.getWeight({6}, {7});
        idx = (w > 0) ? 7 : 6;
    }

    return idx;
}