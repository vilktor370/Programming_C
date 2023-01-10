import cv2
import numpy as np

def main():
    img1 = cv2.imread('/Users/haochenyu/Desktop/Programming_C/Lenna.png', 1)
    img2 = cv2.imread("/Users/haochenyu/Desktop/Programming_C/prince_book.jpg", 1)
    size = (400, 400)
    resized_img1 = cv2.resize(img1, size).astype(np.float32) / 255
    resized_img2 = cv2.resize(img2, size).astype(np.float32) / 255
    mask1 = np.ones((400, 400, 3)).astype(np.float32) * 0.2
    mask2 = np.ones((400, 400, 3)).astype(np.float32) * 0.8
    mask1[200:, :, :] = 0
    mask1[200:, :, :] = 0
    final = resized_img1 * mask1 + resized_img2 * mask2
    show = (final * 255).astype(np.uint8)
    cv2.imshow("image", show)
    cv2.waitKey(0)
if __name__ == '__main__':
    main()