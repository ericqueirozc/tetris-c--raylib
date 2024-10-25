#include "view.h"

View::View()
{
    // Scale = 4;                  // Integral scaling of a 16:9 base resolution
    Width = 300;  // ** Width & Height **
    Height = 600; // Currently a Scale of a 16:9 resolution

    // Center of Viewport at scale
    Center.X = Width / 2;
    Center.Y = Height / 2;
}