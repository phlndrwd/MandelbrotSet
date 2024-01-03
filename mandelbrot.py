import numpy as np
import matplotlib.pyplot as plt

def mandelbrot(c, max_iter):
    z = 0
    for i in range(max_iter):
        z = z**2 + c
        if abs(z) > 2:
            return i
    return max_iter

def mandelbrot_set(width, height, xAxis, yAxis, max_iter):
    mandelbrot_image = np.zeros((height, width), dtype=int)

    for j in range(height):
        y = yAxis[j]
        for i in range(width):
            x = xAxis[i]
            c = x + 1j * y
            # print(c)
            mandelbrot_image[j, i] = mandelbrot(c, max_iter)

    return mandelbrot_image

# Set the parameters for the Mandelbrot set
#width, height = 800, 800
width, height = 1333, 1000  # Increase the resolution

x_min, x_max = -2, 1
y_min, y_max = -1.5, 1.5
max_iter = 40

xAxis = np.linspace(x_min, x_max, width, endpoint=True)
yAxis = np.linspace(y_min, y_max, height, endpoint=True)

# Plot the Mandelbrot set
mandelbrot_image = mandelbrot_set(width, height, xAxis, yAxis, max_iter)

fig = plt.figure(figsize=(8, 8))
plt.imshow(mandelbrot_image, extent=(x_min, x_max, y_min, y_max), cmap='viridis', interpolation='bilinear')
plt.colorbar()
plt.title("Mandelbrot Set")
plt.xlabel("Real")
plt.ylabel("Imaginary")
plt.show()
 