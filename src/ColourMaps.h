#ifndef COLOURMAPS_H
#define COLOURMAPS_H

#include <array>

#include "Colour.h"
#include "Constants.h"

/**
 * @brief Colour maps use 256 colours. Data taken from: https://www.kennethmoreland.com/color-advice/
 */

class ColourMaps {
public:
  ColourMaps();

  const Colour getBlackBody(const unsigned&);
  const Colour getCoolWarm(const unsigned&);
  const Colour getGreyscale(const unsigned&);
  const Colour getPlasma(const unsigned&);
  const Colour getTurbo(const unsigned&);
  const Colour getViridis(const unsigned&);

private:
  std::array<Colour, consts::kNumberOfColours> blackBody_ =
    {Colour(0, 0, 0), Colour(3, 1, 1), Colour(7, 2, 1), Colour(10, 3, 2),
    Colour(13, 4, 2), Colour(16, 5, 3), Colour(18, 6, 3), Colour(20, 7, 4),
    Colour(22, 8, 4), Colour(24, 9, 5), Colour(26, 10, 5), Colour(27, 11, 6),
    Colour(29, 11, 6), Colour(30, 12, 7), Colour(32, 13, 8), Colour(33, 14, 8),
    Colour(34, 15, 9), Colour(36, 15, 9), Colour(37, 16, 10), Colour(38, 16, 10),
    Colour(40, 17, 11), Colour(41, 17, 11), Colour(43, 18, 12), Colour(44, 18, 12),
    Colour(46, 18, 13), Colour(47, 19, 13), Colour(49, 19, 14), Colour(50, 19, 14),
    Colour(52, 20, 15), Colour(54, 20, 15), Colour(55, 20, 15), Colour(57, 21, 16),
    Colour(58, 21, 16), Colour(60, 21, 16), Colour(62, 22, 17), Colour(63, 22, 17),
    Colour(65, 22, 17), Colour(66, 23, 18), Colour(68, 23, 18), Colour(70, 23, 18),
    Colour(71, 24, 19), Colour(73, 24, 19), Colour(75, 24, 19), Colour(76, 25, 20),
    Colour(78, 25, 20), Colour(80, 25, 20), Colour(81, 25, 20), Colour(83, 26, 21),
    Colour(85, 26, 21), Colour(86, 26, 21), Colour(88, 26, 21), Colour(90, 27, 22),
    Colour(91, 27, 22), Colour(93, 27, 22), Colour(95, 27, 22), Colour(97, 28, 23),
    Colour(98, 28, 23), Colour(100, 28, 23), Colour(102, 28, 23), Colour(104, 29, 24),
    Colour(105, 29, 24), Colour(107, 29, 24), Colour(109, 29, 24), Colour(111, 29, 25),
    Colour(112, 30, 25), Colour(114, 30, 25), Colour(116, 30, 25), Colour(118, 30, 26),
    Colour(119, 30, 26), Colour(121, 31, 26), Colour(123, 31, 26), Colour(125, 31, 27),
    Colour(127, 31, 27), Colour(128, 31, 27), Colour(130, 31, 27), Colour(132, 32, 28),
    Colour(134, 32, 28), Colour(136, 32, 28), Colour(137, 32, 28), Colour(139, 32, 29),
    Colour(141, 32, 29), Colour(143, 32, 29), Colour(145, 33, 29), Colour(147, 33, 30),
    Colour(148, 33, 30), Colour(150, 33, 30), Colour(152, 33, 31), Colour(154, 33, 31),
    Colour(156, 33, 31), Colour(158, 33, 31), Colour(160, 33, 32), Colour(161, 34, 32),
    Colour(163, 34, 32), Colour(165, 34, 32), Colour(167, 34, 33), Colour(169, 34, 33),
    Colour(171, 34, 33), Colour(173, 34, 33), Colour(175, 34, 34), Colour(177, 34, 34),
    Colour(178, 34, 34), Colour(179, 36, 34), Colour(180, 38, 34), Colour(181, 40, 33),
    Colour(182, 42, 33), Colour(183, 44, 33), Colour(184, 45, 33), Colour(185, 47, 32),
    Colour(186, 49, 32), Colour(187, 50, 32), Colour(188, 52, 31), Colour(189, 53, 31),
    Colour(190, 55, 31), Colour(191, 56, 31), Colour(192, 58, 30), Colour(193, 59, 30),
    Colour(194, 61, 30), Colour(195, 62, 29), Colour(196, 64, 29), Colour(197, 65, 28),
    Colour(198, 66, 28), Colour(199, 68, 28), Colour(200, 69, 27), Colour(201, 71, 27),
    Colour(202, 72, 26), Colour(203, 73, 26), Colour(204, 75, 25), Colour(205, 76, 25),
    Colour(206, 77, 24), Colour(207, 79, 24), Colour(208, 80, 23), Colour(209, 82, 23),
    Colour(210, 83, 22), Colour(211, 84, 21), Colour(212, 85, 21), Colour(213, 87, 20),
    Colour(214, 88, 19), Colour(215, 89, 19), Colour(216, 91, 18), Colour(217, 92, 17),
    Colour(218, 93, 16), Colour(219, 95, 15), Colour(220, 96, 14), Colour(221, 97, 13),
    Colour(222, 98, 12), Colour(223, 100, 11), Colour(224, 101, 9), Colour(225, 102, 8),
    Colour(226, 104, 7), Colour(227, 105, 5), Colour(227, 107, 5), Colour(227, 109, 6),
    Colour(228, 110, 7), Colour(228, 112, 7), Colour(228, 114, 8), Colour(228, 116, 8),
    Colour(229, 118, 9), Colour(229, 119, 10), Colour(229, 121, 10), Colour(229, 123, 11),
    Colour(229, 124, 12), Colour(230, 126, 12), Colour(230, 128, 13), Colour(230, 130, 14),
    Colour(230, 131, 14), Colour(230, 133, 15), Colour(230, 135, 15), Colour(231, 136, 16),
    Colour(231, 138, 17), Colour(231, 140, 17), Colour(231, 141, 18), Colour(231, 143, 19),
    Colour(231, 145, 19), Colour(231, 146, 20), Colour(232, 148, 21), Colour(232, 150, 21),
    Colour(232, 151, 22), Colour(232, 153, 22), Colour(232, 154, 23), Colour(232, 156, 24),
    Colour(232, 158, 24), Colour(232, 159, 25), Colour(232, 161, 26), Colour(232, 162, 26),
    Colour(233, 164, 27), Colour(233, 166, 27), Colour(233, 167, 28), Colour(233, 169, 29),
    Colour(233, 170, 29), Colour(233, 172, 30), Colour(233, 174, 30), Colour(233, 175, 31),
    Colour(233, 177, 32), Colour(233, 178, 32), Colour(233, 180, 33), Colour(233, 181, 34),
    Colour(233, 183, 34), Colour(233, 185, 35), Colour(233, 186, 35), Colour(233, 188, 36),
    Colour(233, 189, 37), Colour(233, 191, 37), Colour(233, 192, 38), Colour(233, 194, 38),
    Colour(233, 195, 39), Colour(233, 197, 40), Colour(233, 199, 40), Colour(233, 200, 41),
    Colour(232, 202, 42), Colour(232, 203, 42), Colour(232, 205, 43), Colour(232, 206, 43),
    Colour(232, 208, 44), Colour(232, 209, 45), Colour(232, 211, 45), Colour(232, 213, 46),
    Colour(232, 214, 47), Colour(232, 216, 47), Colour(231, 217, 48), Colour(231, 219, 48),
    Colour(231, 220, 49), Colour(231, 222, 50), Colour(231, 223, 50), Colour(231, 225, 51),
    Colour(230, 226, 52), Colour(230, 228, 52), Colour(230, 229, 53), Colour(231, 231, 60),
    Colour(233, 231, 69), Colour(234, 232, 78), Colour(236, 233, 87), Colour(237, 234, 94),
    Colour(238, 235, 102), Colour(240, 236, 109), Colour(241, 236, 117), Colour(242, 237, 124),
    Colour(243, 238, 131), Colour(245, 239, 137), Colour(246, 240, 144), Colour(247, 241, 151),
    Colour(248, 241, 158), Colour(249, 242, 164), Colour(249, 243, 171), Colour(250, 244, 177),
    Colour(251, 245, 184), Colour(252, 246, 190), Colour(252, 247, 197), Colour(253, 248, 203),
    Colour(253, 249, 210), Colour(254, 249, 216), Colour(254, 250, 223), Colour(254, 251, 229),
    Colour(255, 252, 236), Colour(255, 253, 242), Colour(255, 254, 249), Colour(255, 255, 255)};

  std::array<Colour, consts::kNumberOfColours> coolWarm_ =
    {Colour(59, 76, 192), Colour(60, 78, 194), Colour(61, 80, 195), Colour(62, 81, 197),
    Colour(63, 83, 199), Colour(64, 85, 200), Colour(66, 87, 202), Colour(67, 88, 203),
    Colour(68, 90, 204), Colour(69, 92, 206), Colour(70, 94, 207), Colour(72, 95, 209),
    Colour(73, 97, 210), Colour(74, 99, 212), Colour(75, 100, 213), Colour(76, 102, 214),
    Colour(78, 104, 216), Colour(79, 106, 217), Colour(80, 107, 218), Colour(81, 109, 219),
    Colour(83, 111, 221), Colour(84, 112, 222), Colour(85, 114, 223), Colour(86, 116, 224),
    Colour(88, 117, 226), Colour(89, 119, 227), Colour(90, 120, 228), Colour(91, 122, 229),
    Colour(93, 124, 230), Colour(94, 125, 231), Colour(95, 127, 232), Colour(97, 129, 233),
    Colour(98, 130, 234), Colour(99, 132, 235), Colour(101, 133, 236), Colour(102, 135, 237),
    Colour(103, 136, 238), Colour(105, 138, 239), Colour(106, 140, 240), Colour(107, 141, 240),
    Colour(109, 143, 241), Colour(110, 144, 242), Colour(111, 146, 243), Colour(113, 147, 244),
    Colour(114, 149, 244), Colour(115, 150, 245), Colour(117, 152, 246), Colour(118, 153, 246),
    Colour(119, 154, 247), Colour(121, 156, 248), Colour(122, 157, 248), Colour(123, 159, 249),
    Colour(125, 160, 249), Colour(126, 162, 250), Colour(128, 163, 250), Colour(129, 164, 251),
    Colour(130, 166, 251), Colour(132, 167, 252), Colour(133, 168, 252), Colour(134, 170, 252),
    Colour(136, 171, 253), Colour(137, 172, 253), Colour(139, 174, 253), Colour(140, 175, 254),
    Colour(141, 176, 254), Colour(143, 177, 254), Colour(144, 178, 254), Colour(146, 180, 254),
    Colour(147, 181, 255), Colour(148, 182, 255), Colour(150, 183, 255), Colour(151, 184, 255),
    Colour(153, 186, 255), Colour(154, 187, 255), Colour(155, 188, 255), Colour(157, 189, 255),
    Colour(158, 190, 255), Colour(159, 191, 255), Colour(161, 192, 255), Colour(162, 193, 255),
    Colour(163, 194, 254), Colour(165, 195, 254), Colour(166, 196, 254), Colour(168, 197, 254),
    Colour(169, 198, 254), Colour(170, 199, 253), Colour(172, 200, 253), Colour(173, 201, 253),
    Colour(174, 201, 252), Colour(176, 202, 252), Colour(177, 203, 252), Colour(178, 204, 251),
    Colour(180, 205, 251), Colour(181, 206, 250), Colour(182, 206, 250), Colour(183, 207, 249),
    Colour(185, 208, 249), Colour(186, 209, 248), Colour(187, 209, 248), Colour(189, 210, 247),
    Colour(190, 211, 246), Colour(191, 211, 246), Colour(192, 212, 245), Colour(193, 212, 244),
    Colour(195, 213, 244), Colour(196, 214, 243), Colour(197, 214, 242), Colour(198, 215, 241),
    Colour(200, 215, 241), Colour(201, 216, 240), Colour(202, 216, 239), Colour(203, 216, 238),
    Colour(204, 217, 237), Colour(205, 217, 236), Colour(206, 218, 235), Colour(208, 218, 234),
    Colour(209, 218, 233), Colour(210, 219, 232), Colour(211, 219, 231), Colour(212, 219, 230),
    Colour(213, 219, 229), Colour(214, 220, 228), Colour(215, 220, 227), Colour(216, 220, 226),
    Colour(217, 220, 225), Colour(218, 220, 224), Colour(219, 221, 222), Colour(220, 221, 221),
    Colour(221, 220, 220), Colour(222, 220, 219), Colour(223, 220, 217), Colour(225, 219, 216),
    Colour(226, 218, 214), Colour(227, 218, 213), Colour(228, 217, 211), Colour(229, 217, 210),
    Colour(229, 216, 209), Colour(230, 216, 207), Colour(231, 215, 206), Colour(232, 214, 204),
    Colour(233, 214, 203), Colour(234, 213, 201), Colour(235, 212, 200), Colour(235, 211, 198),
    Colour(236, 211, 197), Colour(237, 210, 195), Colour(238, 209, 194), Colour(238, 208, 192),
    Colour(239, 207, 191), Colour(239, 206, 189), Colour(240, 206, 187), Colour(241, 205, 186),
    Colour(241, 204, 184), Colour(242, 203, 183), Colour(242, 202, 181), Colour(243, 201, 180),
    Colour(243, 200, 178), Colour(244, 199, 177), Colour(244, 198, 175), Colour(244, 197, 173),
    Colour(245, 196, 172), Colour(245, 195, 170), Colour(245, 193, 169), Colour(246, 192, 167),
    Colour(246, 191, 166), Colour(246, 190, 164), Colour(246, 189, 162), Colour(247, 188, 161),
    Colour(247, 186, 159), Colour(247, 185, 158), Colour(247, 184, 156), Colour(247, 183, 155),
    Colour(247, 181, 153), Colour(247, 180, 151), Colour(247, 179, 150), Colour(247, 177, 148),
    Colour(247, 176, 147), Colour(247, 175, 145), Colour(247, 173, 144), Colour(247, 172, 142),
    Colour(247, 171, 140), Colour(247, 169, 139), Colour(247, 168, 137), Colour(247, 166, 136),
    Colour(246, 165, 134), Colour(246, 163, 133), Colour(246, 162, 131), Colour(246, 160, 129),
    Colour(245, 159, 128), Colour(245, 157, 126), Colour(245, 156, 125), Colour(244, 154, 123),
    Colour(244, 153, 122), Colour(244, 151, 120), Colour(243, 149, 119), Colour(243, 148, 117),
    Colour(242, 146, 116), Colour(242, 144, 114), Colour(241, 143, 113), Colour(241, 141, 111),
    Colour(240, 139, 110), Colour(240, 138, 108), Colour(239, 136, 107), Colour(238, 134, 105),
    Colour(238, 133, 104), Colour(237, 131, 102), Colour(237, 129, 101), Colour(236, 127, 99),
    Colour(235, 125, 98), Colour(234, 124, 96), Colour(234, 122, 95), Colour(233, 120, 93),
    Colour(232, 118, 92), Colour(231, 116, 91), Colour(230, 114, 89), Colour(229, 112, 88),
    Colour(229, 111, 86), Colour(228, 109, 85), Colour(227, 107, 84), Colour(226, 105, 82),
    Colour(225, 103, 81), Colour(224, 101, 79), Colour(223, 99, 78), Colour(222, 97, 77),
    Colour(221, 95, 75), Colour(220, 93, 74), Colour(219, 91, 73), Colour(218, 89, 71),
    Colour(216, 86, 70), Colour(215, 84, 69), Colour(214, 82, 68), Colour(213, 80, 66),
    Colour(212, 78, 65), Colour(211, 76, 64), Colour(209, 73, 62), Colour(208, 71, 61),
    Colour(207, 69, 60), Colour(206, 67, 59), Colour(204, 64, 57), Colour(203, 62, 56),
    Colour(202, 59, 55), Colour(200, 57, 54), Colour(199, 54, 53), Colour(198, 52, 52),
    Colour(196, 49, 50), Colour(195, 46, 49), Colour(193, 43, 48), Colour(192, 40, 47),
    Colour(191, 37, 46), Colour(189, 34, 45), Colour(188, 30, 44), Colour(186, 26, 43),
    Colour(185, 22, 41), Colour(183, 17, 40), Colour(182, 11, 39), Colour(180, 4, 38)};

  std::array<Colour, consts::kNumberOfColours> plasma_ =
    {Colour(13, 8, 135), Colour(16, 7, 136), Colour(19, 7, 137), Colour(22, 7, 138),
    Colour(25, 6, 140), Colour(27, 6, 141), Colour(29, 6, 142), Colour(32, 6, 143),
    Colour(34, 6, 144), Colour(36, 6, 145), Colour(38, 5, 145), Colour(40, 5, 146),
    Colour(42, 5, 147), Colour(44, 5, 148), Colour(46, 5, 149), Colour(47, 5, 150),
    Colour(49, 5, 151), Colour(51, 5, 151), Colour(53, 4, 152), Colour(55, 4, 153),
    Colour(56, 4, 154), Colour(58, 4, 154), Colour(60, 4, 155), Colour(62, 4, 156),
    Colour(63, 4, 156), Colour(65, 4, 157), Colour(67, 3, 158), Colour(68, 3, 158),
    Colour(70, 3, 159), Colour(72, 3, 159), Colour(73, 3, 160), Colour(75, 3, 161),
    Colour(76, 2, 161), Colour(78, 2, 162), Colour(80, 2, 162), Colour(81, 2, 163),
    Colour(83, 2, 163), Colour(85, 2, 164), Colour(86, 1, 164), Colour(88, 1, 164),
    Colour(89, 1, 165), Colour(91, 1, 165), Colour(92, 1, 166), Colour(94, 1, 166),
    Colour(96, 1, 166), Colour(97, 0, 167), Colour(99, 0, 167), Colour(100, 0, 167),
    Colour(102, 0, 167), Colour(103, 0, 168), Colour(105, 0, 168), Colour(106, 0, 168),
    Colour(108, 0, 168), Colour(110, 0, 168), Colour(111, 0, 168), Colour(113, 0, 168),
    Colour(114, 1, 168), Colour(116, 1, 168), Colour(117, 1, 168), Colour(119, 1, 168),
    Colour(120, 1, 168), Colour(122, 2, 168), Colour(123, 2, 168), Colour(125, 3, 168),
    Colour(126, 3, 168), Colour(128, 4, 168), Colour(129, 4, 167), Colour(131, 5, 167),
    Colour(132, 5, 167), Colour(134, 6, 166), Colour(135, 7, 166), Colour(136, 8, 166),
    Colour(138, 9, 165), Colour(139, 10, 165), Colour(141, 11, 165), Colour(142, 12, 164),
    Colour(143, 13, 164), Colour(145, 14, 163), Colour(146, 15, 163), Colour(148, 16, 162),
    Colour(149, 17, 161), Colour(150, 19, 161), Colour(152, 20, 160), Colour(153, 21, 159),
    Colour(154, 22, 159), Colour(156, 23, 158), Colour(157, 24, 157), Colour(158, 25, 157),
    Colour(160, 26, 156), Colour(161, 27, 155), Colour(162, 29, 154), Colour(163, 30, 154),
    Colour(165, 31, 153), Colour(166, 32, 152), Colour(167, 33, 151), Colour(168, 34, 150),
    Colour(170, 35, 149), Colour(171, 36, 148), Colour(172, 38, 148), Colour(173, 39, 147),
    Colour(174, 40, 146), Colour(176, 41, 145), Colour(177, 42, 144), Colour(178, 43, 143),
    Colour(179, 44, 142), Colour(180, 46, 141), Colour(181, 47, 140), Colour(182, 48, 139),
    Colour(183, 49, 138), Colour(184, 50, 137), Colour(186, 51, 136), Colour(187, 52, 136),
    Colour(188, 53, 135), Colour(189, 55, 134), Colour(190, 56, 133), Colour(191, 57, 132),
    Colour(192, 58, 131), Colour(193, 59, 130), Colour(194, 60, 129), Colour(195, 61, 128),
    Colour(196, 62, 127), Colour(197, 64, 126), Colour(198, 65, 125), Colour(199, 66, 124),
    Colour(200, 67, 123), Colour(201, 68, 122), Colour(202, 69, 122), Colour(203, 70, 121),
    Colour(204, 71, 120), Colour(204, 73, 119), Colour(205, 74, 118), Colour(206, 75, 117),
    Colour(207, 76, 116), Colour(208, 77, 115), Colour(209, 78, 114), Colour(210, 79, 113),
    Colour(211, 81, 113), Colour(212, 82, 112), Colour(213, 83, 111), Colour(213, 84, 110),
    Colour(214, 85, 109), Colour(215, 86, 108), Colour(216, 87, 107), Colour(217, 88, 106),
    Colour(218, 90, 106), Colour(218, 91, 105), Colour(219, 92, 104), Colour(220, 93, 103),
    Colour(221, 94, 102), Colour(222, 95, 101), Colour(222, 97, 100), Colour(223, 98, 99),
    Colour(224, 99, 99), Colour(225, 100, 98), Colour(226, 101, 97), Colour(226, 102, 96),
    Colour(227, 104, 95), Colour(228, 105, 94), Colour(229, 106, 93), Colour(229, 107, 93),
    Colour(230, 108, 92), Colour(231, 110, 91), Colour(231, 111, 90), Colour(232, 112, 89),
    Colour(233, 113, 88), Colour(233, 114, 87), Colour(234, 116, 87), Colour(235, 117, 86),
    Colour(235, 118, 85), Colour(236, 119, 84), Colour(237, 121, 83), Colour(237, 122, 82),
    Colour(238, 123, 81), Colour(239, 124, 81), Colour(239, 126, 80), Colour(240, 127, 79),
    Colour(240, 128, 78), Colour(241, 129, 77), Colour(241, 131, 76), Colour(242, 132, 75),
    Colour(243, 133, 75), Colour(243, 135, 74), Colour(244, 136, 73), Colour(244, 137, 72),
    Colour(245, 139, 71), Colour(245, 140, 70), Colour(246, 141, 69), Colour(246, 143, 68),
    Colour(247, 144, 68), Colour(247, 145, 67), Colour(247, 147, 66), Colour(248, 148, 65),
    Colour(248, 149, 64), Colour(249, 151, 63), Colour(249, 152, 62), Colour(249, 154, 62),
    Colour(250, 155, 61), Colour(250, 156, 60), Colour(250, 158, 59), Colour(251, 159, 58),
    Colour(251, 161, 57), Colour(251, 162, 56), Colour(252, 163, 56), Colour(252, 165, 55),
    Colour(252, 166, 54), Colour(252, 168, 53), Colour(252, 169, 52), Colour(253, 171, 51),
    Colour(253, 172, 51), Colour(253, 174, 50), Colour(253, 175, 49), Colour(253, 177, 48),
    Colour(253, 178, 47), Colour(253, 180, 47), Colour(253, 181, 46), Colour(254, 183, 45),
    Colour(254, 184, 44), Colour(254, 186, 44), Colour(254, 187, 43), Colour(254, 189, 42),
    Colour(254, 190, 42), Colour(254, 192, 41), Colour(253, 194, 41), Colour(253, 195, 40),
    Colour(253, 197, 39), Colour(253, 198, 39), Colour(253, 200, 39), Colour(253, 202, 38),
    Colour(253, 203, 38), Colour(252, 205, 37), Colour(252, 206, 37), Colour(252, 208, 37),
    Colour(252, 210, 37), Colour(251, 211, 36), Colour(251, 213, 36), Colour(251, 215, 36),
    Colour(250, 216, 36), Colour(250, 218, 36), Colour(249, 220, 36), Colour(249, 221, 37),
    Colour(248, 223, 37), Colour(248, 225, 37), Colour(247, 226, 37), Colour(247, 228, 37),
    Colour(246, 230, 38), Colour(246, 232, 38), Colour(245, 233, 38), Colour(245, 235, 39),
    Colour(244, 237, 39), Colour(243, 238, 39), Colour(243, 240, 39), Colour(242, 242, 39),
    Colour(241, 244, 38), Colour(241, 245, 37), Colour(240, 247, 36), Colour(240, 249, 33)};

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

  std::array<Colour, consts::kNumberOfColours> viridis_ =
    {Colour(68, 1, 84), Colour(68, 2, 86), Colour(69, 4, 87), Colour(69, 5, 89),
    Colour(70, 7, 90), Colour(70, 8, 92), Colour(70, 10, 93), Colour(70, 11, 94),
    Colour(71, 13, 96), Colour(71, 14, 97), Colour(71, 16, 99), Colour(71, 17, 100),
    Colour(71, 19, 101), Colour(72, 20, 103), Colour(72, 22, 104), Colour(72, 23, 105),
    Colour(72, 24, 106), Colour(72, 26, 108), Colour(72, 27, 109), Colour(72, 28, 110),
    Colour(72, 29, 111), Colour(72, 31, 112), Colour(72, 32, 113), Colour(72, 33, 115),
    Colour(72, 35, 116), Colour(72, 36, 117), Colour(72, 37, 118), Colour(72, 38, 119),
    Colour(72, 40, 120), Colour(72, 41, 121), Colour(71, 42, 122), Colour(71, 44, 122),
    Colour(71, 45, 123), Colour(71, 46, 124), Colour(71, 47, 125), Colour(70, 48, 126),
    Colour(70, 50, 126), Colour(70, 51, 127), Colour(70, 52, 128), Colour(69, 53, 129),
    Colour(69, 55, 129), Colour(69, 56, 130), Colour(68, 57, 131), Colour(68, 58, 131),
    Colour(68, 59, 132), Colour(67, 61, 132), Colour(67, 62, 133), Colour(66, 63, 133),
    Colour(66, 64, 134), Colour(66, 65, 134), Colour(65, 66, 135), Colour(65, 68, 135),
    Colour(64, 69, 136), Colour(64, 70, 136), Colour(63, 71, 136), Colour(63, 72, 137),
    Colour(62, 73, 137), Colour(62, 74, 137), Colour(62, 76, 138), Colour(61, 77, 138),
    Colour(61, 78, 138), Colour(60, 79, 138), Colour(60, 80, 139), Colour(59, 81, 139),
    Colour(59, 82, 139), Colour(58, 83, 139), Colour(58, 84, 140), Colour(57, 85, 140),
    Colour(57, 86, 140), Colour(56, 88, 140), Colour(56, 89, 140), Colour(55, 90, 140),
    Colour(55, 91, 141), Colour(54, 92, 141), Colour(54, 93, 141), Colour(53, 94, 141),
    Colour(53, 95, 141), Colour(52, 96, 141), Colour(52, 97, 141), Colour(51, 98, 141),
    Colour(51, 99, 141), Colour(50, 100, 142), Colour(50, 101, 142), Colour(49, 102, 142),
    Colour(49, 103, 142), Colour(49, 104, 142), Colour(48, 105, 142), Colour(48, 106, 142),
    Colour(47, 107, 142), Colour(47, 108, 142), Colour(46, 109, 142), Colour(46, 110, 142),
    Colour(46, 111, 142), Colour(45, 112, 142), Colour(45, 113, 142), Colour(44, 113, 142),
    Colour(44, 114, 142), Colour(44, 115, 142), Colour(43, 116, 142), Colour(43, 117, 142),
    Colour(42, 118, 142), Colour(42, 119, 142), Colour(42, 120, 142), Colour(41, 121, 142),
    Colour(41, 122, 142), Colour(41, 123, 142), Colour(40, 124, 142), Colour(40, 125, 142),
    Colour(39, 126, 142), Colour(39, 127, 142), Colour(39, 128, 142), Colour(38, 129, 142),
    Colour(38, 130, 142), Colour(38, 130, 142), Colour(37, 131, 142), Colour(37, 132, 142),
    Colour(37, 133, 142), Colour(36, 134, 142), Colour(36, 135, 142), Colour(35, 136, 142),
    Colour(35, 137, 142),Colour(35, 138, 141), Colour(34, 139, 141), Colour(34, 140, 141),
    Colour(34, 141, 141), Colour(33, 142, 141), Colour(33, 143, 141), Colour(33, 144, 141),
    Colour(33, 145, 140), Colour(32, 146, 140), Colour(32, 146, 140), Colour(32, 147, 140),
    Colour(31, 148, 140), Colour(31, 149, 139), Colour(31, 150, 139), Colour(31, 151, 139),
    Colour(31, 152, 139), Colour(31, 153, 138), Colour(31, 154, 138), Colour(30, 155, 138),
    Colour(30, 156, 137), Colour(30, 157, 137), Colour(31, 158, 137), Colour(31, 159, 136),
    Colour(31, 160, 136), Colour(31, 161, 136), Colour(31, 161, 135), Colour(31, 162, 135),
    Colour(32, 163, 134), Colour(32, 164, 134), Colour(33, 165, 133), Colour(33, 166, 133),
    Colour(34, 167, 133), Colour(34, 168, 132), Colour(35, 169, 131), Colour(36, 170, 131),
    Colour(37, 171, 130), Colour(37, 172, 130), Colour(38, 173, 129), Colour(39, 173, 129),
    Colour(40, 174, 128), Colour(41, 175, 127), Colour(42, 176, 127), Colour(44, 177, 126),
    Colour(45, 178, 125), Colour(46, 179, 124), Colour(47, 180, 124), Colour(49, 181, 123),
    Colour(50, 182, 122), Colour(52, 182, 121), Colour(53, 183, 121), Colour(55, 184, 120),
    Colour(56, 185, 119), Colour(58, 186, 118), Colour(59, 187, 117), Colour(61, 188, 116),
    Colour(63, 188, 115), Colour(64, 189, 114), Colour(66, 190, 113), Colour(68, 191, 112),
    Colour(70, 192, 111), Colour(72, 193, 110), Colour(74, 193, 109), Colour(76, 194, 108),
    Colour(78, 195, 107), Colour(80, 196, 106), Colour(82, 197, 105), Colour(84, 197, 104),
    Colour(86, 198, 103), Colour(88, 199, 101), Colour(90, 200, 100), Colour(92, 200, 99),
    Colour(94, 201, 98), Colour(96, 202, 96), Colour(99, 203, 95), Colour(101, 203, 94),
    Colour(103, 204, 92), Colour(105, 205, 91), Colour(108, 205, 90), Colour(110, 206, 88),
    Colour(112, 207, 87), Colour(115, 208, 86), Colour(117, 208, 84), Colour(119, 209, 83),
    Colour(122, 209, 81), Colour(124, 210, 80), Colour(127, 211, 78), Colour(129, 211, 77),
    Colour(132, 212, 75), Colour(134, 213, 73), Colour(137, 213, 72), Colour(139, 214, 70),
    Colour(142, 214, 69), Colour(144, 215, 67), Colour(147, 215, 65), Colour(149, 216, 64),
    Colour(152, 216, 62), Colour(155, 217, 60), Colour(157, 217, 59), Colour(160, 218, 57),
    Colour(162, 218, 55), Colour(165, 219, 54), Colour(168, 219, 52), Colour(170, 220, 50),
    Colour(173, 220, 48), Colour(176, 221, 47), Colour(178, 221, 45), Colour(181, 222, 43),
    Colour(184, 222, 41), Colour(186, 222, 40), Colour(189, 223, 38), Colour(192, 223, 37),
    Colour(194, 223, 35), Colour(197, 224, 33), Colour(200, 224, 32), Colour(202, 225, 31),
    Colour(205, 225, 29), Colour(208, 225, 28), Colour(210, 226, 27), Colour(213, 226, 26),
    Colour(216, 226, 25), Colour(218, 227, 25), Colour(221, 227, 24), Colour(223, 227, 24),
    Colour(226, 228, 24), Colour(229, 228, 25), Colour(231, 228, 25), Colour(234, 229, 26),
    Colour(236, 229, 27), Colour(239, 229, 28), Colour(241, 229, 29), Colour(244, 230, 30),
    Colour(246, 230, 32), Colour(248, 230, 33), Colour(251, 231, 35), Colour(253, 231, 37)};
};

#endif // COLOURMAPS_H
