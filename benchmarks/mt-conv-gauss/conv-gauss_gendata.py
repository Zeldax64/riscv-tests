def img():
	import numpy as np
	import cv2
	from matplotlib import pyplot as plt
	img=cv2.imread('imgBig_lena.bmp',0);
	height, width = img.shape
	arq=open('img2.h','w')
	bufaux="unsigned char image["+str(height)+"]["+str(width)+"] = {\n"
	arq.write(bufaux)

	for x in range(height):
		arq.write("{")
		for y in range(width):
			buf= "%d" %(img[x][y])
			if(y!=width-1):
				buf=buf+","
			arq.write(buf)
		arq.write("}")
		if(x!=height-1):
			arq.write(",")
			arq.write("\n")
	bufaux="};"
	arq.write(bufaux)

	arq.close()
def result():
	import numpy as np
	import cv2
	from matplotlib import pyplot as plt
	img2=cv2.imread('result.png',0);
	height, width = img2.shape
	arq=open('resultsobel.h','w')
	bufaux="unsigned char resultimage["+str(height)+"]["+str(width)+"] = {\n"
	arq.write(bufaux)

	for x in range(height):
		arq.write("{")
		for y in range(width):
			buf= "%d" %(img2[x][y])
			if(y!=width-1):
				buf=buf+","
			arq.write(buf)
		arq.write("}")
		if(x!=height-1):
			arq.write(",")
			arq.write("\n")
	bufaux="};"
	arq.write(bufaux)

	arq.close()

def main():
	img()
	result()
main()