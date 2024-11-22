<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

# S1 | Prog: Workshop

<!-- code_chunk_output -->

- [S1 | Prog: Workshop](#s1--prog-workshop)
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

| Avant                  |               Après               |
| ---------------------- | :-------------------------------: |
| ![](./images/logo.png) | ![](./output/keep_green_only.png) |

## ⭐ Échanger les canaux

| Avant                  |              Après              |
| ---------------------- | :-----------------------------: |
| ![](./images/logo.png) | ![](./output/channels_swap.png) |

## ⭐ Noir & Blanc

| Avant                  |               Après               |
| ---------------------- | :-------------------------------: |
| ![](./images/logo.png) | ![](./output/black_and_white.png) |

## ⭐ Négatif

| Avant                  |          Après           |
| ---------------------- | :----------------------: |
| ![](./images/logo.png) | ![](./output/invert.png) |

## ⭐ Dégradé

|              Rendu               |
| :------------------------------: |
| ![](./output/black_gradient.png) |

## ⭐⭐ Miroir

| Avant                  |          Après           |
| ---------------------- | :----------------------: |
| ![](./images/logo.png) | ![](./output/mirror.png) |

## ⭐⭐ Image bruitée

| Avant                  |          Après          |
| ---------------------- | :---------------------: |
| ![](./images/logo.png) | ![](./output/noise.png) |

## ⭐⭐ Rotation de 90°

| Avant                  |           Après            |
| ---------------------- | :------------------------: |
| ![](./images/logo.png) | ![](./output/rotate90.png) |

## ⭐⭐ RGB split

| Avant                  |            Après            |
| ---------------------- | :-------------------------: |
| ![](./images/logo.png) | ![](./output/rgb_split.png) |

## ⭐⭐ Luminosité

| Avant                   |   Après éclaircissement   |
| ----------------------- | :-----------------------: |
| ![](./images/photo.jpg) | ![](./output/lighten.jpg) |

| Avant                   |  Après assombrissement   |
| ----------------------- | :----------------------: |
| ![](./images/photo.jpg) | ![](./output/darken.jpg) |

## ⭐⭐(⭐) Disque

| Rendu                    |
| ------------------------ |
| ![](./output/circle.png) |

- ### ⭐ Cercle
  | Rendu                         |
  | ----------------------------- |
  | ![](./output/line_circle.png) |
- ### ⭐⭐ Animation
  | Rendu              |
  | ------------------ |
  | ![](./output/.png) |
- ### ⭐⭐⭐ Rosace
  | Rendu                    |
  | ------------------------ |
  | ![](./output/circle.png) |

## ⭐⭐ Mosaïque

| Avant                  |                          Après                           |
| ---------------------- | :------------------------------------------------------: |
| ![](./images/logo.png) | <img src="./output/mosaic.png" width="300" height="345"> |

Pour la mosaïque, j'ai multiplié la taille de l'image par cinq par rapport à l'image d'origine.

À chaque fois que mon compteur x équivaut à la width ou que mon compteur y équivaut à la height de l'image d'origine, le compteur en question se réinitialise à zéro.

```cpp

```

## ⭐⭐⭐⭐ Mosaïque miroir

| Avant                  |                              Après                              |
| ---------------------- | :-------------------------------------------------------------: |
| ![](./images/logo.png) | <img src="./output/mirror_mosaic.png" width="300" height="345"> |

Pour la mosaïque miroir,

## ⭐⭐⭐ Glitch

## ⭐⭐⭐ Tri de pixels

## ⭐⭐⭐ Dégradé dans l'espace de couleur Lab

## ⭐⭐⭐(⭐) Fractale de Mandelbrot

| Rendu                        |
| ---------------------------- |
| ![](./output/mandelbrot.png) |

## ⭐⭐⭐(⭐) Tramage

| Avant                   |           Après           |
| ----------------------- | :-----------------------: |
| ![](./images/photo.jpg) | ![](./output/tramage.png) |

## Quelques effets

| Avant                  |                            Après                             |
| ---------------------- | :----------------------------------------------------------: |
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
