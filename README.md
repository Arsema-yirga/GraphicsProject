                         Waving Flag  of Bonaire & Chrome Logo


            Project Overview
This project demonstrates fundamental computer graphics concepts using OpenGL, consisting of two main components: a dynamically animated waving flag and a realistic Chrome logo. It showcases primitive drawing, RGB color representation, geometric transformations, and animation through continuous updates and mathematical modeling.
        
        
        
        
           Transformations Used
 Translation  glTranslatef Used to move objects across the screen. The flag rises up the pole on startup via an accumulating offset, while the Chrome logo is positioned on the right half of the window with an added sine-based vertical float for smooth continuous motion.

Rotation  glRotatef Applied to the Chrome logo to create a spinning animation around its center.

Scaling glScalef Creates a pulsing effect by oscillating the Chrome logo's size between 0.90 and 1.15 smoothly over time. A fixed large scale factor also converts the unit size logo geometry to window coordinates.

Sinusoidal Waveform (Flag Wave) Each vertex of the flag is displaced along the Y-axis using a sine function. The phase decrements every timer tick, scrolling the wave from right to left to simulate wind.

Matrix Stack glPushMatrix / glPopMatrix Wraps each object's transformations in an isolated context so changes to one object don't affect the other.
         




           Implementation Approach
All transformations were applied using the OpenGL model-view matrix stack. The flag is divided into 160 thin vertical quad strips, each displaced individually by the wave function.The Chrome logo is built in unit coordinates from three 120° colored arcs, layered circles, and then scaled up to screen size. A single glutTimerFunc callback fires every 16 ms, updating all animation variables and triggering a redraw.
 
         



             Challenges Faced
 Synchronizing Animations Ensuring the wave, rotation, scale pulse, and float all update smoothly within the same timer callback required careful timing adjustments.

 Transformation Order  OpenGL applies matrix operations in reverse order, causing confusion when combining translation, rotation, and scale. Incorrect ordering caused the logo to orbit rather than spin in place.

Realistic Flag Waving  Fine-tuning wave amplitude and frequency was needed to avoid geometry tearing between adjacent strips and to keep the diagonal color boundary aligned with the wave.

Color Accuracy  Selecting accurate RGB values for the Chrome logo's segments required research and refinement.

Isolated Transformation Contexts The matrix stack calls had to be scoped correctly to prevent the flag's translation from leaking into the Chrome logo's transformation.





## Group Members

| No. | Name            | Student ID   |
|-----|-----------------|--------------|
| 1   | Arsema Yirga    | GUR/02128/16 |
| 2   | Bitanya Setegn  | GUR/01308/16 |
| 3   | Efrata Dejene   | GUR/03243/16 |
| 4   | Genet Zewdu     | GUR/01479/16 |
| 5   | Kalkidan Birara | GUR/02768/16 |
| 6   | Biruk Mitiku    | GUR/01116/16 |