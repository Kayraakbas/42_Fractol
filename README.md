# Fractol - 42 Network Project
**Interactive Fractal Explorer using MiniLibX**

<div align="center">
  <img src="screenShots/Screenshot from 2025-06-02 15-04-10.png" width="400"/>
  <img src="screenShots/Screenshot from 2025-06-02 15-07-47.png" width="400"/>
  <img src="screenShots/Screenshot from 2025-06-02 15-11-35.png" width="400"/>
  <img src="screenShots/Screenshot from 2025-06-02 15-13-52.png" width="400"/>
</div>

## 🌌 Overview
Fractol renders mathematically-generated fractals in real-time using the MiniLibX graphics library. Explore infinite complexity through the Mandelbrot and Julia sets, with zoom capabilities revealing intricate patterns at any scale. This project demonstrates mathematical visualization, graphics programming, and event handling in C.

## 🚀 Features
### Mandatory Implementation
- **Mandelbrot & Julia sets** with customizable parameters
- **Infinite zoom** with mouse scroll (within computational limits)
- **Depth visualization** using color gradients
- **Multiple Julia configurations** via command-line parameters
- **Graceful exit** handling (ESC key and window close)
- **Input validation** with error messages

### 🔥 Bonus Features
- ** Fractal Types**: Mandelbrot, Julia
- **View navigation**: Pan with arrow keys
- **Dynamic coloring system**:
  - Adaptive iteration depth (`+`/`-` keys)

## 🛠️ Installation
bash
# Clone repository
git clone https://github.com/Kayraakbas/42_Fractol.git
cd fractol

# Compile mandatory version
make

# Compile bonus version (recommended)
make bonus

## 🎮 Usage
- **./fractol mandelbrot
- **./fractol julia -0.7 0.27015
