import cv2
import numpy as np

def main():
    img1 = cv2.imread('/Users/haochenyu/Desktop/Programming_C/Lenna.png', 1)
    img2 = cv2.imread("/Users/haochenyu/Desktop/Programming_C/prince_book.jpg", 1)
    # size = (400, 400)
    resized_img1 = img1.copy()
    # resized_img1 = cv2.resize(img1, size)
    # resized_img2 = cv2.resize(img2, size)
    
    # b,g,r = resized_img1.copy(), resized_img1.copy(), resized_img1.copy()
    # b[:, :, 1] = 0
    # b[:, :, 2] = 0
    
    # g[:, :, 0] = 0
    # g[:, :, 2] = 0
    
    # r[:, :, 0] = 0
    # r[:, :, 1] = 0
    
    b,g,r = resized_img1[:, :, 0],resized_img1[:, :, 1],resized_img1[:, :, 2]
    # cv2.findContour(r, )
    bin_img = b.copy()
    bin_img[g > 127] = 255
    bin_img[g < 128] = 0
    
    contours, _ = cv2.findContours(bin_img, 3, 2)
    show = cv2.drawContours(resized_img1, contours, -1, (255, 0, 0), 2)
    print(contours)
    
    # show image
    # show = np.hstack([b, g, r])
    cv2.imshow("b,g,r", bin_img)
    cv2.waitKey(0)
if __name__ == '__main__':
    main()