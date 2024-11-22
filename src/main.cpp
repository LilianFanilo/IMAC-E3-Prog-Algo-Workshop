#include <sil/sil.hpp>
#include "random.hpp"
#include <algorithm>

void keep_green_only(sil::Image& image)
{
    for (glm::vec3& color : image.pixels())
    {
        color.r = 0.f;
        color.b = 0.f;
    }
}

void channels_swap(sil::Image& image)
{
    for (glm::vec3& color : image.pixels())
    {
        std::swap(color.r,color.b);
    }
    
}

void black_and_white(sil::Image& image)
{
    for (glm::vec3& color : image.pixels())
    {
        float luminance =  0.2126f * color.r + 0.7152f * color.g + 0.0722f * color.b;

        color = glm::vec3{luminance} ;
    } 
}

void invert(sil::Image& image)
{
    for (glm::vec3& color : image.pixels())
    {
        color = glm::vec3{1.f} - color ;
    }
    
}

void black_gradiant(sil::Image& image)
{
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x,y) = glm::vec3{static_cast<float>(x) / (static_cast<float>(image.width() - 1.f))};
        }    
    }
    
}

void mirror(sil::Image& image)
{
    for (int x{0}; x < image.width() / 2 ; x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            int mirrorX  {image.width() - 1 - x};
            std::swap(image.pixel(x,y),image.pixel(mirrorX,y));
        }
    }
}

void noise(sil::Image& image) 
{
    for (int x{0}; x < image.width() ; x++)
    {
        for (int y{0}; y < image.height(); y++)
        {            
            int random_noise {random_int(0,10)};
            if (random_noise == 0)
            {
                float random_color {static_cast<float>(random_int(0,255))};        

                switch (random_int(0,3))
                {
                case 0:
                    image.pixel(x,y).r = random_color; 
                    break;
                
                case 1:
                    image.pixel(x,y).g = random_color; 
                    break;
                
                case 2:
                    image.pixel(x,y).b = random_color; 
                    break;
                
                default:
                    break;
                }    
            }
        }
    }
}

void rotate90(sil::Image& image)
{
    int new_width {image.height()};
    int new_height {image.width()};

    sil::Image new_image{new_width, new_height};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            new_image.pixel((new_width - 1 - y), x) = image.pixel(x,y);
        }
    }
    new_image.save("output/rotate90.png");
}

void rgb_split(sil::Image& image)
{
    sil::Image new_image{image.width(), image.height()};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            int blue_split {x - 30};
            int red_split {x + 30};

            if (blue_split < 0)
            {
                blue_split = 0;
            }
            else if (red_split >= image.width())
            {
                red_split = image.width() - 1;
            }
            
            new_image.pixel(x,y).g = image.pixel(x,y).g;
            new_image.pixel(blue_split,y).b = image.pixel(x,y).b;
            new_image.pixel(red_split,y).r = image.pixel(x,y).r;
        }
    }

    new_image.save("output/rgb_split.png");
}

void luminosity(sil::Image& image)
{
    sil::Image lighten{image.width(), image.height()};
    sil::Image darken{image.width(), image.height()};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {

            lighten.pixel(x,y).r = pow(image.pixel(x,y).r,0.5);
            lighten.pixel(x,y).g = pow(image.pixel(x,y).g,0.5);
            lighten.pixel(x,y).b = pow(image.pixel(x,y).b,0.5);

            darken.pixel(x,y).r = pow(image.pixel(x,y).r,1.1);
            darken.pixel(x,y).g = pow(image.pixel(x,y).g,1.1);
            darken.pixel(x,y).b = pow(image.pixel(x,y).b,1.1);

        }
    }

    lighten.save("output/lighten.jpg");
    darken.save("output/darken.jpg");
}

void circle(sil::Image& image)
{
    int rayon {75};
    int centerX {image.width() / 2};
    int centerY {image.height() / 2};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            double calculus {pow(x - centerX ,2) + pow(y - centerY ,2)};
            if(calculus <= pow(rayon, 2))
            {
                image.pixel(x,y) = glm::vec3{1.f};
            }
        }
    }
}

void line_circle(sil::Image& image)
{
    int rayon {75};
    int centerX {image.width() / 2};
    int centerY {image.height() / 2};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            double calculus {pow(x - centerX ,2) + pow(y - centerY ,2)};
            if(calculus < pow(rayon, 2) && calculus > pow(rayon-10,2))
            {
                image.pixel(x,y) = glm::vec3{1.f};
            }
        }
    }
}

void animation(sil::Image& image)
{
    int gif_number {5};

    for (int i = 0; i < gif_number; i++)
    {
        sil::Image new_image{500,500};

        int rayon {75};
        int centerX {new_image.width() / 2};
        int centerY {new_image.height() / 2};

        for (int x{0}; x < new_image.width(); x++)
        {
            for (int y{0}; y < new_image.height(); y++)
            {
                double calculus {pow(x - ((new_image.width() / gif_number) * i) ,2) + pow(y - centerY ,2)};
                if(calculus <= pow(rayon, 2))
                {
                    new_image.pixel(x,y) = glm::vec3{1.f};
                }
            }
        }

        new_image.save("output/animation/gif_"+ std::to_string(i) +".png");
    }

}

void rosace(sil::Image& image)
{

}

void mosaic(sil::Image& image)
{
    sil::Image img_mosaic{(image.width() * 5),(image.height() * 5)};
    int counterX {};
    int counterY {};


        for (int x{0}; x < img_mosaic.width(); x++)
        {
            counterX++;

            if (counterX == image.width())
            {
                counterX = 0 ;
            }
            

            for (int y{0}; y < img_mosaic.height(); y++)
            {
                counterY++;

                if (counterY == image.height())
                {
                    counterY = 0;
                }
                
                img_mosaic.pixel(x,y) = image.pixel(counterX,counterY);
                
            }
        }
    
    img_mosaic.save("output/mosaic.png");
}

void new_effect(sil::Image& image)
{
    sil::Image img_mosaic{(image.width() * 5),(image.height() * 5)};
    int counterX {};
    int counterY {};

    int mirrorX  {image.width() - 1 - counterX};



        for (int x{0}; x < img_mosaic.width(); x++)
        {
            counterX++;

            if (counterX == image.width())
            {
                counterX = 0 ;
            }
            

            for (int y{0}; y < img_mosaic.height(); y++)
            {
                counterY++;

                if (counterY == image.height())
                {
                    counterY = 0;
                }
                
                if (counterY % 2 == 0)
                {
                    img_mosaic.pixel(x,y) = image.pixel(counterX,counterY);
                }
                else
                {
                    img_mosaic.pixel(x,y) = image.pixel(mirrorX,counterY);

                }
                
                
                
            }
        }
    
    img_mosaic.save("output/new_effect.png");
}

void mirror_mosaic(sil::Image& image)
{
    sil::Image img_mosaic{(image.width() * 5),(image.height() * 5)};
    int counterX {};
    int counterY {};
    int isMirrorX {};
    int isMirrorY {};


        for (int x{0}; x < img_mosaic.width(); x++)
        {
            counterX++;

            if (counterX == image.width())
            {
                counterX = 0 ;
                isMirrorX ++;
            }
            

            for (int y{0}; y < img_mosaic.height(); y++)
            {
                counterY++;

                if (counterY == image.height())
                {
                    counterY = 0;
                    isMirrorY ++;

                    if (isMirrorY > 4)
                    {
                        isMirrorY = 0;
                    }
                    
                }
                
                if (isMirrorX % 2 != 0)
                {
                    if (isMirrorY % 2 != 0)
                    {
                        img_mosaic.pixel(x,y) = image.pixel((image.width() - 1 - counterX),(image.height() - 1 - counterY));
                    } 
                    else 
                    {
                        img_mosaic.pixel(x,y) = image.pixel((image.width() - 1 - counterX),counterY);
                    }
                } 
                else
                {
                    if (isMirrorY % 2 != 0)
                    {
                        img_mosaic.pixel(x,y) = image.pixel(counterX, (image.height() - 1 - counterY));
                    } 
                    else 
                    {
                        img_mosaic.pixel(x,y) = image.pixel(counterX,counterY);
                    }
                }            
            }
        }
    
            img_mosaic.save("output/mirror_mosaic.png");
}

void glitch(sil::Image& image)
{
    int random_glitch {random_int(1, 15)};

        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                for (int i = 0; i < random_glitch; i++)
                {
                    int size_x_max {random_int(1,15)};
                    int size_y_max {random_int(1,15)};

                    int randomX_1 {random_int(1,image.width())};
                    int randomY_1 {random_int(1,image.height())};
                    int randomX_2 {random_int(1,image.width())};
                    int randomY_2 {random_int(1,image.height())};

                    for (int size_x = 0; size_x < size_x_max; size_x++)
                    {
                            int width_1 {randomX_1 + size_x};
                            int width_2 {randomX_2 + size_x};

                            if ( width_1 >= image.width())
                            {
                                width_1 = image.width() - 1 ;
                            }
                            else {
                                continue;
                            }
                             if ( width_2 >= image.width() )
                            {
                                width_2 = image.width() - 1 ;
                            }
                            else {
                                continue;
                            }
                        for (int size_y = 0; size_y < size_y_max; size_y++)
                        {
                            int height_1 {randomY_1 + size_y};

                            int height_2 {randomY_2 + size_y};
                            
                            if ( height_1 >= image.height() )
                            {
                                height_1 = image.height() - 1 ;
                            }
                             else {
                                continue;
                            }
                            if ( height_2 >= image.height() )
                            {
                                height_2 = image.height() - 1 ;
                            } else {
                                continue;
                            }
                            
                            std::swap(image.pixel(width_1 , height_1),image.pixel(width_2 , height_2));
                        }
                    }
                    
                }
            }
        }
}

void new_pixel_sorting(sil::Image& image)
{
    for (int y{0}; y < image.height(); y++)
    {
        for (int x{0}; x < image.width(); x++)
        {
            for (int i = x; i < image.width(); i++)
            {

                float brightness_x = 0.2126f * image.pixel(x,y).r + 0.7152f * image.pixel(x,y).g + 0.0722f * image.pixel(x,y).b;

                float brightness_i = 0.2126f * image.pixel(i,y).r + 0.7152f * image.pixel(i,y).g + 0.0722f * image.pixel(i,y).b;

                if (brightness_x < brightness_i)
                {
                    std::swap(image.pixel(x,y),image.pixel(i,y));
                }
            }
            
        }
    }
}

void pixel_sorting(sil::Image& image)
{

}

struct Lab {float L; float a; float b;};

Lab linear_srgb_to_oklab(glm::vec3 c) 
{
    float l = 0.4122214708f * c.r + 0.5363325363f * c.g + 0.0514459929f * c.b;
	float m = 0.2119034982f * c.r + 0.6806995451f * c.g + 0.1073969566f * c.b;
	float s = 0.0883024619f * c.r + 0.2817188376f * c.g + 0.6299787005f * c.b;

    float l_ = cbrtf(l);
    float m_ = cbrtf(m);
    float s_ = cbrtf(s);

    return {
        0.2104542553f*l_ + 0.7936177850f*m_ - 0.0040720468f*s_,
        1.9779984951f*l_ - 2.4285922050f*m_ + 0.4505937099f*s_,
        0.0259040371f*l_ + 0.7827717662f*m_ - 0.8086757660f*s_,
    };
}

void gradient_lab(sil::Image& image)
{
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            float gradient = static_cast<float>(x) / static_cast<float>(image.width() - 1);

            glm::vec3 t = {1.f - gradient, gradient, 0.f};

            image.pixel(x,y) = t;
        }    
    }
    // linear_srgb_to_oklab(image);
}

# include <complex>
void mandelbrot(sil::Image& image)
{
    for (int x {0}; x < image.width(); x++)
    {
        for (int y {0}; y < image.height(); y++)
        {

            float x0 = (static_cast<float>(x) / static_cast<float>(image.width())) * 2.f - 1.5f;
            float y0 = (static_cast<float>(y) / static_cast<float>(image.height())) * 2.0f - 1.0f;

            std::complex<float> c {x0, y0};
            std::complex<float> z {0.0, 0.0};

            int iteration = 0;
            int max_iteration = 100;

            while (std::abs(z) < 2.0 && iteration < max_iteration)
            {
                z = z * z + c;
                iteration++;
            }

            if (iteration == max_iteration)
            {
                image.pixel(x,y) = glm::vec3{0.f};
            }
            else
            {
                float t = static_cast<float>(iteration) / static_cast<float>(max_iteration);
                image.pixel(x,y) = glm::vec3{t};

            }
        
        }
    }
    
}

void tramage(sil::Image& image)
{
    const int bayer_n = 4;
    float bayer_matrix_4x4[][bayer_n] = {
        {    -0.5,       0,  -0.375,   0.125 },
        {    0.25,   -0.25,   0.375, - 0.125 },
        { -0.3125,  0.1875, -0.4375,  0.0625 },
        {  0.4375, -0.0625,  0.3125, -0.1875 },
    };

    for (int y = 0; y < image.height(); y++) {

        for (int x = 0; x < image.width(); x++) {
                float bayer_value = bayer_matrix_4x4[y % bayer_n][x % bayer_n];
    
                glm::vec3 color = image.pixel(x, y);
    
                float luminance = 0.2126f * color.r + 0.7152f * color.g + 0.0722f * color.b;
    
                if (luminance > bayer_value) {
                    image.pixel(x, y) = glm::vec3{0.8f};
                } else {
                    image.pixel(x, y) = glm::vec3{0.f};
                }
        }
    }
    
}

int main()
{
    // {
    //     sil::Image image{"images/logo.png"};
    //     keep_green_only(image); 
    //     image.save("output/keep_green_only.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     channels_swap(image);
    //     image.save("output/channels_swap.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     black_and_white(image);
    //     image.save("output/black_and_white.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     invert(image);
    //     image.save("output/invert.png");
    // }
    // {
    //     sil::Image image{300/*width*/, 200/*height*/};
    //     black_gradiant(image);
    //     image.save("output/black_gradient.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     mirror(image);
    //     image.save("output/mirror.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     noise(image);
    //     image.save("output/noise.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     rotate90(image);
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     rgb_split(image);
    // }
    // {
    //     sil::Image image{"images/photo.jpg"};
    //     luminosity(image);
    // }
    // {
    //     sil::Image image{500,500};
    //     circle(image);
    //     image.save("output/circle.png");
    // }
    // {
    //     sil::Image image{500,500};
    //     line_circle(image);
    //     image.save("output/line_circle.png");
    // }
    // {
    //     sil::Image image{500,500};
    //     animation(image);
    // }
    // {
    //     sil::Image image{500,500};
    //     rosace(image);
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     mosaic(image);   
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     new_effect(image);   
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     mirror_mosaic(image);   
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     glitch(image);
    //     image.save("output/glitch.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     new_pixel_sorting(image);
    //     image.save("output/new_pixel_sorting.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     pixel_sorting(image);
    //     image.save("output/pixel_sorting.png");
    // }
    // {
    //     sil::Image image{500,500};
    //     gradient_lab(image);
    //     image.save("output/gradient_lab.png");
    // }
    {
        sil::Image image{500,500};
        mandelbrot(image);
        image.save("output/mandelbrot.png");        
    }
    // {
    //     sil::Image image{"images/photo.jpg"};
    //     tramage(image);
    //     image.save("output/tramage.png");        
    // }

}