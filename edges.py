import cv2
import numpy as np


class Edge():
    def __init__(self, img, kernel_x):
        self.kx = kernel_x
        self.ky = np.rot90(kernel_x)
        self.Ix = cv2.filter2D(img, -1, self.kx)
        self.Iy = cv2.filter2D(img, -1, self.ky)
        self.magnitude = ((self.Ix) ** 2 + (self.Iy) ** 2) ** 0.5
        self.orentation = np.arctan2(self.Iy, self.Ix)
        
    def show(self):
        return np.hstack([self.Ix, self.Iy, self.magnitude])

def main():
    img = cv2.imread("/Users/haochenyu/Desktop/Programming_C/Lenna.png", 0)
    # Robert
    robert = np.array([
        [0, 1],
        [-1, 0]
    ])
    # Prewitt
    prewitt = np.array([
        [-1, 0, 1],
        [-1, 0, 1],
        [-1, 0, 1]
    ])

    # Sobel
    sobel = np.array([
        [-1, 0, 1],
        [-2, 0, 2],
        [-1, 0, 1]
    ])
    
    edge_robert = Edge(img, robert)
    edge_prewitt = Edge(img, prewitt)
    edge_sobel = Edge(img, sobel)
    
    show = np.vstack([
        edge_robert.show(),
        edge_prewitt.show(),
        edge_sobel.show()
    ])
    # cv2.imwrite("edge.png", show)
    cv2.imshow("image", show)
    cv2.waitKey(0)

if __name__ == '__main__':
    main()