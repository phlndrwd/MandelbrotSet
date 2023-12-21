#ifndef COLOURMAPS_H
#define COLOURMAPS_H

#include <array>

#include "Colour.h"
#include "Constants.h"

class ColourMaps {
public:
  ColourMaps();

  Colour getTurbo(const unsigned&);

private:
  std::array<Colour, consts::kNumberOfColours> turbo_ =
    {Colour(48, 18, 59), Colour(50, 21, 67), Colour(51, 24, 74), Colour(52, 27, 81),
    Colour(53, 30, 88), Colour(54, 33, 95), Colour(55, 36, 102), Colour(56, 39, 109),
    Colour(57, 42, 115), Colour(58, 45, 121), Colour(59, 47, 128), Colour(60, 50, 134),
    Colour(61, 53, 139), Colour(62, 56, 145), Colour(63, 59, 151), Colour(63, 62, 156),
    Colour(64, 64, 162), Colour(65, 67, 167), Colour(65, 70, 172), Colour(66, 73, 177),
    Colour(66, 75, 181), Colour(67, 78, 186), Colour(68, 81, 191), Colour(68, 84, 195),
    Colour(68, 86, 199), Colour(69, 89, 203), Colour(69, 92, 207), Colour(69, 94, 211),
    Colour(70, 97, 214), Colour(70, 100, 218), Colour(70, 102, 221), Colour(70, 105, 224),
    Colour(70, 107, 227), Colour(71, 110, 230), Colour(71, 113, 233), Colour(71, 115, 235),
    Colour(71, 118, 238), Colour(71, 120, 240), Colour(71, 123, 242), Colour(70, 125, 244),
    Colour(70, 128, 246), Colour(70, 130, 248), Colour(70, 133, 250), Colour(70, 135, 251),
    Colour(69, 138, 252), Colour(69, 140, 253), Colour(68, 143, 254), Colour(67, 145, 254),
    Colour(66, 148, 255), Colour(65, 150, 255), Colour(64, 153, 255), Colour(62, 155, 254),
    Colour(61, 158, 254), Colour(59, 160, 253), Colour(58, 163, 252), Colour(56, 165, 251),
    Colour(55, 168, 250), Colour(53, 171, 248), Colour(51, 173, 247), Colour(49, 175, 245),
    Colour(47, 178, 244), Colour(46, 180, 242), Colour(44, 183, 240), Colour(42, 185, 238),
    Colour(40, 188, 235), Colour(39, 190, 233), Colour(37, 192, 231), Colour(35, 195, 228),
    Colour(34, 197, 226), Colour(32, 199, 223), Colour(31, 201, 221), Colour(30, 203, 218),
    Colour(28, 205, 216), Colour(27, 208, 213), Colour(26, 210, 210), Colour(26, 212, 208),
    Colour(25, 213, 205), Colour(24, 215, 202), Colour(24, 217, 200), Colour(24, 219, 197),
    Colour(24, 221, 194), Colour(24, 222, 192), Colour(24, 224, 189), Colour(25, 226, 187),
    Colour(25, 227, 185), Colour(26, 228, 182), Colour(28, 230, 180), Colour(29, 231, 178),
    Colour(31, 233, 175), Colour(32, 234, 172), Colour(34, 235, 170), Colour(37, 236, 167),
    Colour(39, 238, 164), Colour(42, 239, 161), Colour(44, 240, 158), Colour(47, 241, 155),
    Colour(50, 242, 152), Colour(53, 243, 148), Colour(56, 244, 145), Colour(60, 245, 142),
    Colour(63, 246, 138), Colour(67, 247, 135), Colour(70, 248, 132), Colour(74, 248, 128),
    Colour(78, 249, 125), Colour(82, 250, 122), Colour(85, 250, 118), Colour(89, 251, 115),
    Colour(93, 252, 111), Colour(97, 252, 108), Colour(101, 253, 105), Colour(105, 253, 102),
    Colour(109, 254, 98), Colour(113, 254, 95), Colour(117, 254, 92), Colour(121, 254, 89),
    Colour(125, 255, 86), Colour(128, 255, 83), Colour(132, 255, 81), Colour(136, 255, 78),
    Colour(139, 255, 75), Colour(143, 255, 73), Colour(146, 255, 71), Colour(150, 254, 68),
    Colour(153, 254, 66), Colour(156, 254, 64), Colour(159, 253, 63), Colour(161, 253, 61),
    Colour(164, 252, 60), Colour(167, 252, 58), Colour(169, 251, 57), Colour(172, 251, 56),
    Colour(175, 250, 55), Colour(177, 249, 54), Colour(180, 248, 54), Colour(183, 247, 53),
    Colour(185, 246, 53), Colour(188, 245, 52), Colour(190, 244, 52), Colour(193, 243, 52),
    Colour(195, 241, 52), Colour(198, 240, 52), Colour(200, 239, 52), Colour(203, 237, 52),
    Colour(205, 236, 52), Colour(208, 234, 52), Colour(210, 233, 53), Colour(212, 231, 53),
    Colour(215, 229, 53), Colour(217, 228, 54), Colour(219, 226, 54), Colour(221, 224, 55),
    Colour(223, 223, 55), Colour(225, 221, 55), Colour(227, 219, 56), Colour(229, 217, 56),
    Colour(231, 215, 57), Colour(233, 213, 57), Colour(235, 211, 57), Colour(236, 209, 58),
    Colour(238, 207, 58), Colour(239, 205, 58), Colour(241, 203, 58), Colour(242, 201, 58),
    Colour(244, 199, 58), Colour(245, 197, 58), Colour(246, 195, 58), Colour(247, 193, 58),
    Colour(248, 190, 57), Colour(249, 188, 57), Colour(250, 186, 57), Colour(251, 184, 56),
    Colour(251, 182, 55), Colour(252, 179, 54), Colour(252, 177, 54), Colour(253, 174, 53),
    Colour(253, 172, 52), Colour(254, 169, 51), Colour(254, 167, 50), Colour(254, 164, 49),
    Colour(254, 161, 48), Colour(254, 158, 47), Colour(254, 155, 45), Colour(254, 153, 44),
    Colour(254, 150, 43), Colour(254, 147, 42), Colour(254, 144, 41), Colour(253, 141, 39),
    Colour(253, 138, 38), Colour(252, 135, 37), Colour(252, 132, 35), Colour(251, 129, 34),
    Colour(251, 126, 33), Colour(250, 123, 31), Colour(249, 120, 30), Colour(249, 117, 29),
    Colour(248, 114, 28), Colour(247, 111, 26), Colour(246, 108, 25), Colour(245, 105, 24),
    Colour(244, 102, 23), Colour(243, 99, 21), Colour(242, 96, 20), Colour(241, 93, 19),
    Colour(240, 91, 18), Colour(239, 88, 17), Colour(237, 85, 16), Colour(236, 83, 15),
    Colour(235, 80, 14), Colour(234, 78, 13), Colour(232, 75, 12), Colour(231, 73, 12),
    Colour(229, 71, 11), Colour(228, 69, 10), Colour(226, 67, 10), Colour(225, 65, 9),
    Colour(223, 63, 8), Colour(221, 61, 8), Colour(220, 59, 7), Colour(218, 57, 7),
    Colour(216, 55, 6), Colour(214, 53, 6), Colour(212, 51, 5), Colour(210, 49, 5),
    Colour(208, 47, 5), Colour(206, 45, 4), Colour(204, 43, 4), Colour(202, 42, 4),
    Colour(200, 40, 3), Colour(197, 38, 3), Colour(195, 37, 3), Colour(193, 35, 2),
    Colour(190, 33, 2), Colour(188, 32, 2), Colour(185, 30, 2), Colour(183, 29, 2),
    Colour(180, 27, 1), Colour(178, 26, 1), Colour(175, 24, 1), Colour(172, 23, 1),
    Colour(169, 22, 1), Colour(167, 20, 1), Colour(164, 19, 1), Colour(161, 18, 1),
    Colour(158, 16, 1), Colour(155, 15, 1), Colour(152, 14, 1), Colour(149, 13, 1),
    Colour(146, 11, 1), Colour(142, 10, 1), Colour(139, 9, 2), Colour(136, 8, 2),
    Colour(133, 7, 2), Colour(129, 6, 2), Colour(126, 5, 2), Colour(122, 4, 3)};

};

#endif // COLOURMAPS_H
