#include "StickerSheet.h"

using mpcs51044::HSLAPixel;
using mpcs51044::Image;
using mpcs51044::StickerSheet;

using std::cout;
using std::endl;

// The place for you
int main() {
    // do your drawing!
    return 0;
}

// // Sticker example 1
// // UChicago campus and the badge
// int main() {
//     Image campus, uchi;
//     campus.readFromFile("refer_image/campus.png");
//     uchi.readFromFile("refer_image/uchicago.png");
//     uchi.scale(0.25);
//     // stickersheet work begin!
//     StickerSheet sheet(campus, 5);
//     sheet.addSticker(uchi, 0, 0);
//     sheet.addSticker(uchi, 900, 0);
//     sheet.addSticker(uchi, 1800, 0);
//     uchi.scale(2);
//     sheet.addSticker(uchi, 400, 0);
//     sheet.addSticker(uchi, 1200, 0);
//     sheet.render().writeToFile("refer_image/uchi_5.png");
    
//     sheet.changeMaxStickers(3); // two bigger uchi were deleted
//     sheet.render().writeToFile("refer_image/uchi_3.png");
//     return 0;
// }

// // Sticker example 2
// // Professor Mike and CPP!
// int main() {
//     Image prof, cpp;
//     prof.readFromFile("refer_image/ProfMike.png");
//     cpp.readFromFile("refer_image/cpp.png");
//     // This time I use an empty base
//     Image blank(2000,2000);
//     prof.scale(500,500);
//     cpp.scale(500,500);
//     StickerSheet sheet(blank,7);
//     sheet.addSticker(prof, 750, 750);
//     sheet.addSticker(cpp, 750, 200);
//     cpp.rotateColor(60);
//     sheet.addSticker(cpp, 1300, 450);
//     cpp.rotateColor(60);
//     sheet.addSticker(cpp, 1300, 1050);
//     cpp.rotateColor(60);
//     sheet.addSticker(cpp, 750, 1300);
//     cpp.rotateColor(60);
//     sheet.addSticker(cpp, 200, 1050);
//     cpp.rotateColor(60);
//     sheet.addSticker(cpp, 200, 450);
//     sheet.render().writeToFile("refer_image/cpp_and_mike.png");
//     return 0;
// }

// // Simply Image modification
// int main() {
//     Image campus_one, campus_two, campus_three;
//     campus_one.readFromFile("refer_image/campus.png");
//     campus_two = campus_one;
//     campus_three = campus_one;

//     campus_one.grayscale();
//     campus_one.writeToFile("refer_image/campus_grayscale.png");

//     campus_two.darken();
//     campus_two.writeToFile("refer_image/campus_darken.png");

//     campus_three.saturate();
//     campus_three.writeToFile("refer_image/campus_saturated.png");
//     return 0;
// }