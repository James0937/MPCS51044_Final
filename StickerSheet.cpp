#include "StickerSheet.h"

namespace mpcs51044 {

void StickerSheet::copy_(const StickerSheet& other) {
    base_ = make_unique<Image>(*other.base_);
    max_ = other.max_;
    stickers_ = vector<unique_ptr<Image>>(max_);
    x_ = vector<unsigned>(max_);
    y_ = vector<unsigned>(max_);
    // Copy each stickers step by step
    for (unsigned i=0; i<max_; i++) {
        if (other.stickers_[i]) {
            stickers_[i] = make_unique<Image>(*other.stickers_[i]);
            x_[i] = other.x_[i];
            y_[i] = other.y_[i];
        }
    }
}

void StickerSheet::move_(StickerSheet&& other) noexcept{
    // Transfer all of the ownership
    base_ = std::move(other.base_);
    max_ = other.max_;
    stickers_ = std::move(other.stickers_);
    x_ = std::move(other.x_);
    y_ = std::move(other.y_);
    // Assign the other to be totally init one
    other.max_ = 0;
}

StickerSheet::StickerSheet() noexcept: base_(make_unique<Image>()), max_(0) {}

StickerSheet::StickerSheet(const Image& picture, unsigned max) noexcept{
    base_ = make_unique<Image>(picture);
    max_ = max;
    if (max != 0) {
        stickers_.resize(max);
        x_.resize(max);
        y_.resize(max);
    }
}

StickerSheet::StickerSheet(const StickerSheet& other){
    copy_(other);
}

StickerSheet::StickerSheet(StickerSheet&& other) noexcept{
    move_(std::move(other));
}

StickerSheet& StickerSheet::operator=(const StickerSheet& other) {
    if (this != &other) {
        StickerSheet temp(other);
        // Swap everything
        swap(base_, temp.base_);
        swap(max_, temp.max_);
        swap(stickers_, temp.stickers_);
        swap(x_, temp.x_);
        swap(y_, temp.y_);
    }
    return *this;
}

StickerSheet& StickerSheet::operator=(StickerSheet&& other) noexcept{
    if (this != &other) {
        move_(std::move(other));
    }
    return *this;
}

void StickerSheet::changeMaxStickers(const unsigned& max) {
    // If max is the same, we don't need any change
    if (max == max_) return;
    max_ = max;
    // Adjust the size for all of the others
    stickers_.resize(max);
    x_.resize(max);
    y_.resize(max);
}

int StickerSheet::addSticker(Image& sticker, unsigned x, unsigned y) {
    unsigned i = 0;
    for (; i < max_ && stickers_[i] != nullptr; i++);
    if (i == max_) { // The Sticker vector is already full
        return -1;
    }
    else { // Available position exists, we can do adding
        stickers_[i] = make_unique<Image>(sticker);
        x_[i] = x;
        y_[i] = y;
        return i;
    }
}

bool StickerSheet::translate(unsigned index, unsigned x, unsigned y) noexcept{
    if (index >= max_ || stickers_[index] == nullptr) {
        return false;
    }
    else {
        x_[index] = x;
        y_[index] = y;
        return true;
    }
}

void StickerSheet::removeSticker(unsigned index) {
    if (index < max_ && stickers_[index] != nullptr)
        stickers_[index].reset(nullptr);
        // We don't need to update x_[index] and y_[index]
}

Image* StickerSheet::getSticker(unsigned index) const {
    return index < max_ ? stickers_[index].get() : nullptr;
}

Image StickerSheet::render() const {
    unsigned int w_out = base_->width();
    unsigned int h_out = base_->height();
    unsigned index;
    for (index = 0; index < max_; index++) {
        if (stickers_[index] != nullptr) {
            if (stickers_[index]->width() + x_[index] > w_out) {
                w_out = stickers_[index]->width() + x_[index];
            }
            if (stickers_[index]->height() + y_[index] > h_out) {
                h_out = stickers_[index]->height() + y_[index];
            }
        }
    }
    Image output = Image(w_out, h_out);
    unsigned x, y;
    // Copy base to output
    for (x = 0; x < base_->width(); x++) {
        for (y = 0; y < base_->height(); y++) {
            HSLAPixel& base_pixel = base_->getPixel(x, y);
            HSLAPixel& output_pixel = output.getPixel(x, y);
            output_pixel = base_pixel;
        }
    }
    // Loop over every sticker
    for (index = 0; index < max_; index++) {
        // Only do so if non-empty
        if (stickers_[index] != nullptr) {
            // Loop over every pixel
            for (x = 0; x < stickers_[index]->width(); x++) {
                for (y = 0; y < stickers_[index]->height(); y++) {
                    HSLAPixel& sticker_pixel = stickers_[index]->getPixel(x, y);
                    // Alpha is not 0. The tolerance is 1e-6
                    if (sticker_pixel.a > 1e-6) {
                        HSLAPixel& output_pixel = output.getPixel(x + x_[index], y + y_[index]);
                        output_pixel = sticker_pixel;
                    }
                }
            }
        }
    }
    return output;
}

};