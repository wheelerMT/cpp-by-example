#include "race.h"

#include <cassert>

void check_properties() {
    Race::StepperBlob blob;
    blob.step();
    assert(blob.total_steps() == 2);

    Race::RandomBlob random_blob(
        []() {
            return 0;
        },
        [](auto gen) {
            return gen();
        });
    random_blob.step();
    assert(random_blob.total_steps() == 0);
}

int main() {
    check_properties();
    std::vector<Race::StepperBlob> blobs(4);
    Race::race(blobs);
}