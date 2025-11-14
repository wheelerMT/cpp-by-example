#include "race.h"

#include <cassert>

void check_properties() {
    Race::StepperBlob blob;
    blob.step();
    assert(blob.total_steps() == 2);
}

int main() {
    check_properties();
    std::vector<Race::StepperBlob> blobs(4);
    Race::race(blobs);
}