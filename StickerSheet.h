#ifndef MPCS_StickerSheet_H
#define MPCS_StickerSheet_H

#include <iostream>
#include <vector>
#include <memory>
#include <mutex>
#include "Image.h"

using std::unique_ptr;
using std::make_unique;
using std::vector;
using std::swap;

namespace mpcs51044 {

class StickerSheet {
private:
    unique_ptr<Image> base_;              // Base picture
    unsigned max_;                        // max number of stickers
    vector<unique_ptr<Image>> stickers_;  // the array of stickers
    vector<unsigned> x_;       // x-coorninate of the stickers
    vector<unsigned> y_;       // y-coorninate of the stickers
    mutable std::mutex m;      // thread safety

    // Helper function for copy constructor and assignment operator
    void copy_(const StickerSheet& other);
    // Helper function for move
    void move_(StickerSheet&& other) noexcept;

public:
    // Creates an empty StickerSheet object
    StickerSheet() noexcept;

    // Initializes the StickerSheet with a base 'picture' and the ability to hold 'max' stickers
    explicit StickerSheet(const Image& picture, unsigned max = 0) noexcept;

    // Thanks to RAII! We only need default deconstructor
    ~StickerSheet() = default;

    // Copy constructor which creates a new StickerSheet that is a copy of another
    StickerSheet(const StickerSheet& other);

    // Move constructor for the StickerSheet
    StickerSheet(StickerSheet&& other) noexcept;

    // Copy assignment operator for setting two StickerSheets equal to one another
    StickerSheet& operator=(const StickerSheet& other);

    // Move assignment operator
    StickerSheet& operator=(StickerSheet&& other) noexcept;

    // Modifies the maximum number of stickers that can be stored without changing existing stickers' indices
    // If the new maximum number is smaller than the current number of stickers,
    // the stickers with indices above 'max-1' will be lost.
    void changeMaxStickers(const unsigned& max);

    // Adds a sticker to the StickerSheet
    // The top-left of the sticker's Image is at (x, y) on the StickerSheet
    // The sticker will be added to the lowest possible layer available
    // Return the zero-based layer index the sticker was added to, or -1 if the sticker cannot be added
    int addSticker(Image& sticker, unsigned x, unsigned y);
    
    // Changes the coordinates of the Image in the specified layer
    // 'index' is the zero-based layer index of the sticker, and (x,y) is the new location
    // Return true if action was successful; o/w false 
    bool translate(unsigned index, unsigned x, unsigned y) noexcept;
    
    // Removes the sticker at the given zero-based layer index
    void removeSticker(unsigned index);

    // Renders the whole StickerSheet on a Image and returns it
    // It works with the order from layer 0 to layer max-1
    // Return an Image object representing the drawn scene
    Image render() const;
};

};

#endif
