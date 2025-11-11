//
// Created by Matthew Wheeler on 29/10/2025.
//

#ifndef CHAPTER6_RACE_H
#define CHAPTER6_RACE_H
#include <vector>
namespace Race {
class Blob {
public:
    virtual ~Blob() = default;
    Blob() = default;
    Blob(Blob const&) = delete;
    Blob& operator=(Blob const&) = delete;

    virtual void step() = 0;
    [[nodiscard]] virtual int total_steps() const = 0;
};

class StepperBlob final : public Blob {
public:
    void step() override {
        y += 2;
    }
    [[nodiscard]] int total_steps() const override {
        return y;
    }

private:
    int y = 0;
};

void draw_blobs(const std::vector<StepperBlob>& blobs);

} // namespace Race
#endif // CHAPTER6_RACE_H
