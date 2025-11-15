//
// Created by Matthew Wheeler on 29/10/2025.
//

#ifndef CHAPTER6_RACE_H
#define CHAPTER6_RACE_H
#include <memory>
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

template <std::invocable<> T, typename U>
class RandomBlob final : public Blob {
public:
    RandomBlob(T gen, U dis)
        : generator{gen}
        , distribution{dis} {}

    void step() override {
        y += static_cast<int>(distribution(generator));
    };

    [[nodiscard]] int total_steps() const override {
        return y;
    }

private:
    int y = 0;
    T generator;
    U distribution;
};

void draw_blobs(const std::vector<std::unique_ptr<Blob>>& blobs);
void move_blobs(const std::vector<std::unique_ptr<Blob>>& blobs);
void race(const std::vector<std::unique_ptr<Blob>>& blobs);

} // namespace Race
#endif // CHAPTER6_RACE_H
