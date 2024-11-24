<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

# Lilian Peuron - S1 | Prog: Workshop

<!-- code_chunk_output -->

- [Lilian Peuron - S1 | Prog: Workshop](#lilian-peuron---s1--prog-workshop)
  - [⭐ Ne garder que le vert](#-ne-garder-que-le-vert)
  - [⭐ Échanger les canaux](#-échanger-les-canaux)
  - [⭐ Noir & Blanc](#-noir--blanc)
  - [⭐ Négatif](#-négatif)
  - [⭐ Dégradé](#-dégradé)
  - [⭐⭐ Miroir](#-miroir)
  - [⭐⭐ Image bruitée](#-image-bruitée)
  - [⭐⭐ Rotation de 90°](#-rotation-de-90)
  - [⭐⭐ RGB split](#-rgb-split)
  - [⭐⭐ Luminosité](#-luminosité)
  - [⭐⭐(⭐) Disque](#-disque)
  - [⭐⭐ Mosaïque](#-mosaïque)
  - [⭐⭐⭐⭐ Mosaïque miroir](#-mosaïque-miroir)
  - [⭐⭐⭐ Glitch](#-glitch)
  - [⭐⭐⭐ Tri de pixels](#-tri-de-pixels)
  - [⭐⭐⭐ Dégradé dans l'espace de couleur Lab](#-dégradé-dans-lespace-de-couleur-lab)
  - [⭐⭐⭐(⭐) Fractale de Mandelbrot](#-fractale-de-mandelbrot)
  - [⭐⭐⭐(⭐) Tramage](#-tramage)
  - [Quelques effets](#quelques-effets)

<!-- /code_chunk_output -->

## ⭐ Ne garder que le vert

| Avant                                                  |                               Après                               |
| ------------------------------------------------------ | :---------------------------------------------------------------: |
| <img src="./images/logo.png" width="300" height="345"> | <img src="./output/keep_green_only.png" width="300" height="345"> |

## ⭐ Échanger les canaux

| Avant                                                  |                              Après                              |
| ------------------------------------------------------ | :-------------------------------------------------------------: |
| <img src="./images/logo.png" width="300" height="345"> | <img src="./output/channels_swap.png" width="300" height="345"> |

## ⭐ Noir & Blanc

| Avant                                                  |                               Après                               |
| ------------------------------------------------------ | :---------------------------------------------------------------: |
| <img src="./images/logo.png" width="300" height="345"> | <img src="./output/black_and_white.png" width="300" height="345"> |

## ⭐ Négatif

| Avant                                                  |                          Après                           |
| ------------------------------------------------------ | :------------------------------------------------------: |
| <img src="./images/logo.png" width="300" height="345"> | <img src="./output/invert.png" width="300" height="345"> |

## ⭐ Dégradé

| Avant                                                        |                              Après                               |
| ------------------------------------------------------------ | :--------------------------------------------------------------: |
| <img src="./output/base_image.png" width="300" height="300"> | <img src="./output/black_gradient.png" width="300" height="300"> |

## ⭐⭐ Miroir

| Avant                                                  |                          Après                           |
| ------------------------------------------------------ | :------------------------------------------------------: |
| <img src="./images/logo.png" width="300" height="345"> | <img src="./output/mirror.png" width="300" height="345"> |

## ⭐⭐ Image bruitée

| Avant                                                  |                          Après                          |
| ------------------------------------------------------ | :-----------------------------------------------------: |
| <img src="./images/logo.png" width="300" height="345"> | <img src="./output/noise.png" width="300" height="345"> |

## ⭐⭐ Rotation de 90°

| Avant                                                  |           Après            |
| ------------------------------------------------------ | :------------------------: |
| <img src="./images/logo.png" width="300" height="345"> | ![](./output/rotate90.png) |

## ⭐⭐ RGB split

| Avant                                                  |                            Après                            |
| ------------------------------------------------------ | :---------------------------------------------------------: |
| <img src="./images/logo.png" width="300" height="345"> | <img src="./output/rgb_split.png" width="300" height="345"> |

## ⭐⭐ Luminosité

| Avant                   |   Après éclaircissement   |
| ----------------------- | :-----------------------: |
| ![](./images/photo.jpg) | ![](./output/lighten.jpg) |

| Avant                   |  Après assombrissement   |
| ----------------------- | :----------------------: |
| ![](./images/photo.jpg) | ![](./output/darken.jpg) |

## ⭐⭐(⭐) Disque

|                            Avant                             |                          Après                           |
| :----------------------------------------------------------: | :------------------------------------------------------: |
| <img src="./output/base_image.png" width="300" height="300"> | <img src="./output/circle.png" width="300" height="300"> |

- ### ⭐ Cercle
  |                            Avant                             |                             Après                             |
  | :----------------------------------------------------------: | :-----------------------------------------------------------: |
  | <img src="./output/base_image.png" width="300" height="300"> | <img src="./output/line_circle.png" width="300" height="300"> |
- ### ⭐⭐ Animation
  |                            Avant                             |                            Après                             |
  | :----------------------------------------------------------: | :----------------------------------------------------------: |
  | <img src="./output/base_image.png" width="300" height="300"> | <img src="./output/base_image.png" width="300" height="300"> |
- ### ⭐⭐⭐ Rosace
  |            Avant             |          Après           |
  | :--------------------------: | :----------------------: |
  | ![](./output/base_image.png) | ![](./output/circle.png) |

## ⭐⭐ Mosaïque

|                         Avant                          |                          Après                           |
| :----------------------------------------------------: | :------------------------------------------------------: |
| <img src="./images/logo.png" width="300" height="345"> | <img src="./output/mosaic.png" width="300" height="345"> |

Pour la mosaïque, j'ai multiplié la taille de l'image par cinq par rapport à l'image d'origine.

À chaque fois que mon compteur x équivaut à la width ou que mon compteur y équivaut à la height de l'image d'origine, le compteur en question se réinitialise à zéro.

```cpp

```

## ⭐⭐⭐⭐ Mosaïque miroir

|                         Avant                          |                              Après                              |
| :----------------------------------------------------: | :-------------------------------------------------------------: |
| <img src="./images/logo.png" width="300" height="345"> | <img src="./output/mirror_mosaic.png" width="300" height="345"> |

Pour la mosaïque miroir,

## ⭐⭐⭐ Glitch

## ⭐⭐⭐ Tri de pixels

## ⭐⭐⭐ Dégradé dans l'espace de couleur Lab

## ⭐⭐⭐(⭐) Fractale de Mandelbrot

|            Avant             |            Après             |
| :--------------------------: | :--------------------------: |
| ![](./output/base_image.png) | ![](./output/mandelbrot.png) |

## ⭐⭐⭐(⭐) Tramage

|          Avant          |           Après           |
| :---------------------: | :-----------------------: |
| ![](./images/photo.jpg) | ![](./output/tramage.png) |

## Quelques effets

|         Avant          |                            Après                             |
| :--------------------: | :----------------------------------------------------------: |
| ![](./images/logo.png) | <img src="./output/new_effect.png" width="300" height="345"> |

Lors de la réalisation de ma mosaïque mirroir. La mosaïque a créé des trames horizontales. Quand on zoom et dézoom, à cause du problème d'affichage. Le visuel change quand on zoom ou dézoom la photo"

```cpp
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
```

| Avant                  |                Après                |
| ---------------------- | :---------------------------------: |
| ![](./images/logo.png) | ![](./output/new_pixel_sorting.png) |

Tri de couleur
